package main

import "fmt"

func main() {

	fmt.Printf("Enter string to be checked: ")

	var str_in string
	fmt.Scanln(&str_in)
	// take user input

	n := len([]rune(str_in))
	str_check := ""

	// reversing the input string and storing it in str_check
	for i := n - 1; i >= 0; i-- {
		str_check += string(str_in[i])
	}

	// if string == its reverse, it's a palindrome
	if str_check == str_in {
		fmt.Println("Palindrome.")
	} else {
		fmt.Println("Not a palindrome.")
	}
}
