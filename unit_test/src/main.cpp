#include "io.hpp"
#include "sortings.hpp"

int main() {
    int arr[] = {1, 8, 2, 5, 3, 11};
	const int arr_size = sizeof(arr) / sizeof(arr[0]);
	
	biv::print_array("До сортровки:", arr, arr_size);
    
    biv::sortings::bubble_sort(arr, arr_size);

    biv::print_array("После сортировки:", arr, arr_size);

    return 0;
}
