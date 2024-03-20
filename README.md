This is my solution to CS50X's readability problem where you're supposed to take any provided written text and output an estimated grade/reading level of the text provided.

According to Coleman-Liau index which is computed using index = 0.0588 * L - 0.296 * S - 15.8 I was to calculate the reading level with the following expectations:

1. f the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output “Grade 16+” instead of outputting an exact index number.
2. If the index number is less than 1, your program should output “Before Grade 1”.
3. Otherwise output the associated reading level between 1 and 16.
