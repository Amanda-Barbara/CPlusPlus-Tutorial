#include <stdio.h>
#include <math.h>

#define BLOCK_SIZE 16

void cpu_matrix_multiplication(int* a, int* b, int* c, const int size)
{
    for(int y=0; y<size;++y)
        for(int x=0; x<size; ++x)
        {
            int sum = 0;
            for (size_t i = 0; i < size; i++)
            {
                sum += a[y*size+i]*b[i*size+x];
            }
            c[y*size+x] = sum;
        }
}

__global__ void gpu_matrix_multiplication(int* a, int* b, int* c, const int size)
{
    int y = blockDim.y*blockIdx.y + threadIdx.y;
    int x = blockDim.x*blockIdx.x + threadIdx.x;

    int sum = 0;
    if(y<size && x<size)
    {
        for (size_t i = 0; i < size; i++)
            sum += a[y*size+i]*b[i*size+x];
        c[y*size+x] = sum;
    }
    
}

int main()
{
    int matrix_size = 1000;
    int mem_size = sizeof(int)* matrix_size * matrix_size;
    int *h_a, *h_b, *h_c, *h_cpu;
    cudaMallocHost((void**)&h_a, mem_size);
    cudaMallocHost((void**)&h_b, mem_size);
    cudaMallocHost((void**)&h_c, mem_size);
    cudaMallocHost((void**)&h_cpu, mem_size);
    for(int y=0; y<matrix_size;++y)
        for(int x=0;x<matrix_size;++x)
        {
            h_a[y*matrix_size+x] = rand()%1024;
            h_b[y*matrix_size+x] = rand()%1024;
        }
            
    // for(int y=0; y<matrix_size;++y)
    //     for(int x=0;x<matrix_size;++x)
            
    
    int *d_a, *d_b, *d_c;
    cudaMalloc((void**)&d_a, mem_size);
    cudaMalloc((void**)&d_b, mem_size);
    cudaMalloc((void**)&d_c, mem_size);

    cudaMemcpy(d_a, h_a, mem_size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, mem_size, cudaMemcpyHostToDevice);

    unsigned int grid_rows = (matrix_size+BLOCK_SIZE-1)/BLOCK_SIZE;
    unsigned int grid_cols = (matrix_size+BLOCK_SIZE-1)/BLOCK_SIZE;

    dim3 dimGrid(grid_cols, grid_rows);
    dim3 dimBlock(BLOCK_SIZE, BLOCK_SIZE); //min warp threads is 32, max is 1024

    gpu_matrix_multiplication<<<dimGrid, dimBlock>>>(d_a, d_b, d_c, matrix_size);

    cudaMemcpy(h_c, d_c, mem_size, cudaMemcpyDeviceToHost);

    cpu_matrix_multiplication(h_a, h_b, h_cpu, matrix_size);

    

    bool passed = true;

    for(int y=0;y<matrix_size;++y)
        for(int x=0; x<matrix_size;++x)
        {
            if(fabs(h_cpu[y*matrix_size+x]-h_c[y*matrix_size+x])>(1.0e-10))
            passed = false;
        }
    printf("Result:%s\n", passed?"Passed.":"Errors.");
    cudaFreeHost(h_a);
    cudaFreeHost(h_b);
    cudaFreeHost(h_c);
    cudaFreeHost(h_cpu);

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);






    return 0;

}