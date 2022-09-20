/*
    Given a string s, return true if it's a palindrome
    Ex. s = "A man, a plan, a canal: Panama" -> true

    2 pointers, outside in, skip non-letters & compare

    Time: O(n)
    Space: O(1)
*/

bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
        while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
        while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
        if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
    }

    return true;
}