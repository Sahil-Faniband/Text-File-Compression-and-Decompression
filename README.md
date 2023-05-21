
# Text File Compression and Decompression using Huffman Coding

This project implements text file compression and decompression using Huffman coding.

## Prerequisites

- C++ compiler
- Standard Template Library (STL)
- `bits/stdc++.h` header file
- `unordered_map` header file

## Running the Code
1. Save the files into same folder and open the folder in VS Code or any other compiler.
2. Recommended to Download .zip file.
3. Compile the code using a C++ compiler.
4. Run the compiled executable.
5. Follow the prompts and instructions displayed on the console.

## Code Structure

The code consists of the following components:

- `HuffmanTree` class: Represents a node in the Huffman tree.
- `Freq` function: Calculates the frequency of characters in the input string.
- `Compare` class: Implements a custom comparison operator for the Huffman tree nodes.
- `print` function: Prints the contents of a priority queue of Huffman tree nodes.
- `makeTree` function: Builds the Huffman tree from the frequency vector.
- `getHuffmanCode` function: Generates Huffman codes for each character in the tree.
- `decompress` function: Decompresses the input text using the Huffman tree.
- `main` function: Implements the user interface and file handling.

## Input and Output Files

The code expects the following files:

- `Text_File.txt`: Contains the input text to compress. ADD "end" KEY WORD IN THE FILE AT THE LAST LINE.
- `Compressed_File.bin`: Creats Compressed binary file and Stores the compressed binary representation of the input text.
- `Decompressed_File.txt`: Outputs the decompressed text file.

## Limitations

- The code may not handle special characters or non-ASCII characters correctly.

## Acknowledgments

The code is based on the principles of Huffman coding.


## Additional Notes

You can change the text file name or a file in program, if you want to compress other file, in this case file name is Text_File.txt.
