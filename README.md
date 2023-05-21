# Text-File-Compression-and-Decompression
This project implements text file compression and decompression using Huffman coding.

# Text File Compression and Decompression using Huffman Coding

This project implements text file compression and decompression using Huffman coding.

## Prerequisites

- C++ compiler
- Standard Template Library (STL)
- `bits/stdc++.h` header file
- `unordered_map` header file

## Running the Code

1. Compile the code using a C++ compiler.
2. Run the compiled executable.
3. Follow the prompts and instructions displayed on the console.

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

- `Text_File.txt`: Contains the input text to compress.
- `Compressed_File.bin`: Stores the compressed binary representation of the input text.
- `Decompressed_File.txt`: Outputs the decompressed text.

## Limitations

- The code may not handle special characters or non-ASCII characters correctly.

## Acknowledgments

The code is based on the principles of Huffman coding.


## Additional Notes


