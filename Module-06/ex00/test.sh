#!/bin/bash

# Colors for better output readability
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Counter for tests
TEST_COUNT=0

# Function to run a test with nice formatting
run_test() {
    local category=$1
    local value=$2
    local comment=$3
    
    echo -e "${BLUE}[${category}]${NC} Testing: ${YELLOW}${value}${NC} ${comment}"
    ./convert ${value}
    echo "-----------------------"
    ((TEST_COUNT++))
}

# Function to print section headers
print_header() {
    echo -e "\n${GREEN}=== $1 ===${NC}"
}

# Run character tests
run_char_tests() {
    print_header "CHARACTER TESTS"
    
    char_tests=("'a'" "'0'" "'+'" "'!'")
    
    for test in "${char_tests[@]}"; do
        run_test "CHAR" "$test" ""
    done
    
    # Displayable vs non-displayable chars
    run_test "CHAR" "32" "(space - lowest displayable)"
    run_test "CHAR" "126" "(tilde - highest displayable)"
    run_test "CHAR" "31" "(non-displayable)"
    run_test "CHAR" "127" "(non-displayable)"
}

# Run integer tests
run_int_tests() {
    print_header "INTEGER TESTS"
    
    int_tests=("0" "42" "-42")
    
    for test in "${int_tests[@]}"; do
        run_test "INT" "$test" ""
    done
    
    run_test "INT" "2147483647" "(INT_MAX)"
    run_test "INT" "-2147483648" "(INT_MIN)"
}

# Run float tests
run_float_tests() {
    print_header "FLOAT TESTS"
    
    float_tests=("0.0f" "4.2f" "-4.2f" "214748.0f" "0.0000042f")
    
    for test in "${float_tests[@]}"; do
        run_test "FLOAT" "$test" ""
    done
    
    # Very small and large values
    run_test "FLOAT" "0.00000000000001f" "(very small)"
    run_test "FLOAT" "3.40282e+38f" "(near float max)"
    run_test "FLOAT" "1.17549e-38f" "(near float min)"
}

# Run double tests
run_double_tests() {
    print_header "DOUBLE TESTS"
    
    double_tests=("0.0" "4.2" "-4.2" "2147483647.0" "0.0000000000000000000042")
    
    for test in "${double_tests[@]}"; do
        run_test "DOUBLE" "$test" ""
    done
}

# Run special value tests
run_special_tests() {
    print_header "SPECIAL VALUE TESTS"
    
    special_tests=("nan" "nanf" "inf" "inff" "+inf" "+inff" "-inf" "-inff")
    
    for test in "${special_tests[@]}"; do
        run_test "SPECIAL" "$test" ""
    done
}

# Run overflow/underflow tests
run_overflow_tests() {
    print_header "OVERFLOW/UNDERFLOW TESTS"
    
    run_test "OVERFLOW" "9999999999999999999999999999.0" "(overflow)"
    run_test "OVERFLOW" "-9999999999999999999999999999.0" "(underflow)"
}

# Main execution
echo -e "${GREEN}=== SCALAR CONVERSION TESTS ===${NC}"
echo -e "${YELLOW}Testing the ScalarConverter class${NC}\n"

# Run all test categories
run_char_tests
run_int_tests
run_float_tests
run_double_tests
run_special_tests
run_overflow_tests

# Print summary
echo -e "\n${GREEN}=== TEST SUMMARY ===${NC}"
echo -e "Total tests executed: ${YELLOW}${TEST_COUNT}${NC}"
echo -e "${BLUE}Done!${NC}"