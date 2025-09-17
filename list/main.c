#include <stdio.h>
#include "list.h"

void test_basic_operations() {
    printf("=== Basic Operations Test ===\n");
    
    // Test 1: Create and free list
    list_t *list = list_alloc();
    printf("1. List created successfully: %s\n", list != NULL ? "PASS" : "FAIL");
    
    // Test 2: Add to front
    list_add_to_front(list, 10);
    list_add_to_front(list, 20);
    list_add_to_front(list, 30);
    printf("2. Add to front: ");
    list_print(list); // Should show: 30 -> 20 -> 10 -> NULL
    
    // Test 3: Add to back
    list_add_to_back(list, 40);
    list_add_to_back(list, 50);
    printf("3. Add to back: ");
    list_print(list); // Should show: 30 -> 20 -> 10 -> 40 -> 50 -> NULL
    
    // Test 4: List length
    printf("4. List length: %d (expected: 5)\n", list_length(list));
    
    // Test 5: Get element at index
    printf("5. Element at index 0: %d (expected: 30)\n", list_get_elem_at(list, 0));
    printf("   Element at index 2: %d (expected: 10)\n", list_get_elem_at(list, 2));
    printf("   Element at index 4: %d (expected: 50)\n", list_get_elem_at(list, 4));
    
    // Test 6: Check if element exists
    printf("6. Contains 20: %s (expected: true)\n", list_is_in(list, 20) ? "true" : "false");
    printf("   Contains 99: %s (expected: false)\n", list_is_in(list, 99) ? "true" : "false");
    
    list_free(list);
    printf("7. List freed successfully\n\n");
}

void test_remove_operations() {
    printf("=== Remove Operations Test ===\n");
    list_t *list = list_alloc();
    
    // Setup list: 100 -> 200 -> 300 -> 400 -> 500 -> NULL
    list_add_to_back(list, 100);
    list_add_to_back(list, 200);
    list_add_to_back(list, 300);
    list_add_to_back(list, 400);
    list_add_to_back(list, 500);
    
    printf("Initial list: ");
    list_print(list);
    
    // Test 1: Remove from front
    elem removed = list_remove_from_front(list);
    printf("1. Removed from front: %d (expected: 100)\n", removed);
    printf("   List after removal: ");
    list_print(list); // Should be: 200 -> 300 -> 400 -> 500 -> NULL
    
    // Test 2: Remove from back
    removed = list_remove_from_back(list);
    printf("2. Removed from back: %d (expected: 500)\n", removed);
    printf("   List after removal: ");
    list_print(list); // Should be: 200 -> 300 -> 400 -> NULL
    
    // Test 3: Remove at index
    removed = list_remove_at_index(list, 1); // Remove middle element
    printf("3. Removed at index 1: %d (expected: 300)\n", removed);
    printf("   List after removal: ");
    list_print(list); // Should be: 200 -> 400 -> NULL
    
    list_free(list);
    printf("4. List freed successfully\n\n");
}

void test_add_at_index() {
    printf("=== Add at Index Test ===\n");
    list_t *list = list_alloc();
    
    // Setup list: 10 -> 30 -> NULL
    list_add_to_back(list, 10);
    list_add_to_back(list, 30);
    
    printf("Initial list: ");
    list_print(list);
    
    // Test 1: Add at index 1 (between 10 and 30)
    list_add_at_index(list, 20, 1);
    printf("1. Added 20 at index 1: ");
    list_print(list); // Should be: 10 -> 20 -> 30 -> NULL
    
    // Test 2: Add at index 0 (front)
    list_add_at_index(list, 5, 0);
    printf("2. Added 5 at index 0: ");
    list_print(list); // Should be: 5 -> 10 -> 20 -> 30 -> NULL
    
    // Test 3: Add at end (index = length)
    list_add_at_index(list, 40, 4);
    printf("3. Added 40 at index 4: ");
    list_print(list); // Should be: 5 -> 10 -> 20 -> 30 -> 40 -> NULL
    
    list_free(list);
    printf("4. List freed successfully\n\n");
}

void test_edge_cases() {
    printf("=== Edge Cases Test ===\n");
    list_t *list = list_alloc();
    
    // Test 1: Empty list operations
    printf("1. Remove from empty front: %d (expected: -1)\n", list_remove_from_front(list));
    printf("2. Remove from empty back: %d (expected: -1)\n", list_remove_from_back(list));
    printf("3. Remove at index from empty: %d (expected: -1)\n", list_remove_at_index(list, 0));
    
    // Test 2: Single element list
    list_add_to_front(list, 100);
    printf("4. Single element list: ");
    list_print(list);
    printf("5. Remove from single element: %d (expected: 100)\n", list_remove_from_back(list));
    
    // Test 3: Invalid indices
    list_add_to_front(list, 200);
    list_add_to_front(list, 300);
    printf("6. Get element at invalid index: %d (expected: -1)\n", list_get_elem_at(list, 5));
    printf("7. Remove at invalid index: %d (expected: -1)\n", list_remove_at_index(list, 5));
    
    list_free(list);
    printf("8. Edge cases completed\n\n");
}

int main() {
    printf("Starting Linked List Tests\n");
    printf("==========================\n\n");
    
    test_basic_operations();
    test_remove_operations();
    test_add_at_index();
    test_edge_cases();
    
    printf("All tests completed!\n");
    return 0;
}