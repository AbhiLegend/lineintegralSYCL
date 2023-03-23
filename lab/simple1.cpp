#include <CL/sycl.hpp>
#include <iostream>
#include <numeric>

using namespace cl::sycl;

int main(int argc, char** argv) {

  constexpr size_t NX = 10;
  constexpr size_t NY = 10;
  constexpr size_t NZ = 10;

  std::vector<float> perm(NX*NY*NZ);
  std::iota(perm.begin(), perm.end(), 1.0f); // populate with values 1, 2, 3, ..., NX*NY*NZ

  float result = 1.0f;

  try {
    //queue q{gpu_selector_v<cl::sycl::gpu_selector>{}};
    //queue q{sycl::gpu_selector_v{}};
     // queue q{sycl::gpu_selector_v<cl::sycl::gpu_selector>{}};
      queue q{sycl::cpu_selector{}};
    std::cout << "Running on "
              << q.get_device().get_info<info::device::name>()
              << std::endl;

    buffer<float, 1> perm_buf(perm.data(), range<1>(NX*NY*NZ));
    buffer<float, 1> result_buf(&result, range<1>(1));

    q.submit([&](handler& cgh) {
      auto perm_acc = perm_buf.get_access<access::mode::read>(cgh);
      auto result_acc = result_buf.get_access<access::mode::write>(cgh);

      cgh.parallel_for<class perm_volume_integral>(
        range<1>(NX*NY*NZ),
        [=](id<1> idx) {
          result_acc[0] *= perm_acc[idx];
        }
      );
    });

    std::cout << "Perm volume integral: " << result << std::endl;

  } catch (sycl::exception& e) {
    std::cerr << "SYCL exception caught: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
