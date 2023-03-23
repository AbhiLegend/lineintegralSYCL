# lineintegralSYCL
<br>The problem statement solved by the given code is to calculate the volume integral of a given 3D permeability field using SYCL parallel computing.</br>
<br>The code first initializes a 3D permeability field of size NX x NY x NZ with values 1, 2, 3, ..., NXNYNZ using the std::iota() function. Then, it creates SYCL buffers for the permeability field and a result variable.

Next, the code submits a SYCL kernel using a parallel_for loop that calculates the volume integral of the permeability field. The kernel multiplies all the values in the permeability field together and stores the result in the result variable.

The code runs the kernel on a chosen device, either a CPU or GPU, depending on the selector that is uncommented. The device name is printed to the console to confirm which device is being used. After the kernel completes, the result of the volume integral is printed to the console.</br>

<br>Note that the volume integral of a 3D field is calculated by taking the product of all the values in the field. In this case, the permeability field represents the permeability of a porous medium, and the volume integral is a measure of the overall permeability of the medium.</br>
