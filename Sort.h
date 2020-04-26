#pragma once

void QuickSortRecurs(int* mas, int first, int last)
{
    int left = first;
    int right = last;
    int mid = mas[(left + right) / 2];
    int temp;
    while (left < right)
    {
        while (mas[left] < mid)
            left++;
        while (mas[right] > mid)
            right--;
        if (left <= right)
        {
            temp = mas[left];
            mas[left] = mas[right];
            mas[right] = temp;
            left++;
            right--;
        }
    }
    if (first < right)
        QuickSortRecurs(mas, first, right);
    if (left < last)
        QuickSortRecurs(mas, left, last);
}

int partition(int* arr, int first, int last)
{
	int temp;
	int pivot = arr[last];
	int index = first;
	for (int i = first; i < last; ++i)
		if (arr[i] < pivot)
		{
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index++;
		}
	temp = arr[last];
	arr[last] = arr[index];
	arr[index] = temp;
	return index;
}
void QuickSort(int* arr, int first, int last)
{
	const int size = 2048;
	int stack[size];
	int top = -1;
	stack[++top] = first;
	stack[++top] = last;

	while (top >= 0)
	{
		last = stack[top--];
		first = stack[top--];
		int pivot_index = partition(arr, first, last);

		if (pivot_index - 1 > first)
		{
			stack[++top] = first;
			stack[++top] = pivot_index - 1;
		}
		if (pivot_index + 1 < last)
		{
			stack[++top] = pivot_index + 1;
			stack[++top] = last;
		}
	}
}