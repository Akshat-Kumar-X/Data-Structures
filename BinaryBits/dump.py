# Constants for the paging system
PAGE_SIZE = 256  # example page size
OUTER_PAGE_TABLE_SIZE = 64  # size of outer page table
INNER_PAGE_TABLE_SIZE = 64  # size of inner page table

# Example Page Tables
outer_page_table = [None] * OUTER_PAGE_TABLE_SIZE  # Initialize outer page table

# Function to initialize inner page tables with dummy data
def initialize_page_tables():
    for outer_index in range(OUTER_PAGE_TABLE_SIZE):
        outer_page_table[outer_index] = [None] * INNER_PAGE_TABLE_SIZE
        for inner_index in range(INNER_PAGE_TABLE_SIZE):
            # Assigning frame numbers (for simplicity, frame number = sum of indices)
            outer_page_table[outer_index][inner_index] = outer_index * INNER_PAGE_TABLE_SIZE + inner_index

# Function to split a logical address into outer page number, inner page number, and offset
def split_logical_address(logical_address):
    outer_page_num = (logical_address >> 14) & 0x3F  # Extract higher bits (assuming 64 as outer size)
    inner_page_num = (logical_address >> 8) & 0x3F   # Extract middle bits
    offset = logical_address & 0xFF                  # Extract lower bits (offset)
    return outer_page_num, inner_page_num, offset

# Function to translate logical address to physical address
def translate_address(logical_address):
    outer_page_num, inner_page_num, offset = split_logical_address(logical_address)

    # Check for page faults (None in the page table entry)
    if outer_page_table[outer_page_num] is None:
        raise Exception(f"Page fault at outer page table index {outer_page_num}")

    frame_number = outer_page_table[outer_page_num][inner_page_num]

    if frame_number is None:
        raise Exception(f"Page fault at inner page table index {inner_page_num} for outer index {outer_page_num}")

    # Calculate the physical address
    physical_address = (frame_number * PAGE_SIZE) + offset
    return physical_address

# Initialize the page tables
initialize_page_tables()

# Test cases
logical_addresses = [
    0x0001,  # Example logical address
    0xF234,  # Another example
    0xABCD,  # One more example
    0xFFFF   # Edge case logical address
]

# Translating logical addresses to physical addresses
for logical_address in logical_addresses:
    try:
        physical_address = translate_address(logical_address)
        print(f"Logical Address: {hex(logical_address)}, Physical Address: {hex(physical_address)}")
    except Exception as e:
        print(e)
