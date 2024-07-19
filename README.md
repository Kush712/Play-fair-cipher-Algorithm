Step-by-Step Description

Step-1 :Input Key and Plaintext:
-First, we ask the user to enter a keyword and the plaintext message they want to encrypt.
  
Step-2 :Prepare the Key Matrix:
-We create a 5x5 grid (key matrix) using the keyword.
-Remove any duplicate letters from the keyword.
-Fill the grid with the letters of the keyword.
-Fill the remaining empty spaces in the grid with the rest of the alphabet, skipping 'J' (we'll --treat 'I' and 'J' as the same letter).

Step-3 : Process Plaintext:
-We prepare the plaintext by splitting it into pairs of letters.
-If there are any pairs of the same letters (like "LL"), we insert an 'X' between them.
-If there's an odd number of characters, we add an 'X' at the end.

Step-4 : Encrypt Each Pair:
-For each pair of letters in the plaintext:
-Find the positions of both letters in the key matrix.
-Depending on their positions, we apply the Playfair cipher rules:
  -Same Row: Replace each letter with the letter immediately to its right (wrapping around to       the start of the row if necessary).
  -Same Column: Replace each letter with the letter immediately below it (wrapping around to the    top of the column if necessary).
  -Rectangle: Replace each letter with the letter in the same row but in the column of the other    letter of the pair.
  
Step-5 : Output the Ciphertext:
-After processing all pairs, we output the resulting ciphertext.
