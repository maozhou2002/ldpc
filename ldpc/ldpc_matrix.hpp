#pragma once
//todo: try matrices from here: http://www.inference.org.uk/mackay/codes/data.html#s9
// https://github.com/tracierenea/GNU-Radio-GSoC2013/tree/master/alist_files

namespace ldpc
{

constexpr int c_num_h_columns = 128;                                   //aka number of bits in codeword;       usually n letter in literature
constexpr int c_message_bits = 64;                                     //original message/data to encode       usually k letter in literature
constexpr int c_check_bits = c_num_h_columns - c_message_bits;         //                                      usually M letter in literature
constexpr int c_num_h_rows = c_check_bits;                             //aka equations         1/2 rate code

constexpr int c_sparsed_max_num_columns = 12;    //maximum number of checks per row


//matrix in sparsed format as output by make-ldpc from here http://www.cs.utoronto.ca/~radford/ftp/LDPC-2012-02-11/pchk.html
//BTW big thank you to the author for his codes written in C and freely available!
//each number tells where is 1 in a row, -1 signals it's the end of the current row
//rows & columns are 0-based this one was generated by ldpc_build_matrix_v02.hpp file & optimized afterwards
constexpr int c_h_matrix[c_num_h_rows][c_sparsed_max_num_columns] = {
        {4, 10, 29, 49, 78, 84, 94, 103, 113, 120, -1},
        {11, 15, 27, 47, 50, 54, 59, 65, 75, 77, -1},
        {34, 40, 46, 53, 54, 82, 98, 101, 103, 124, -1},
        {10, 27, 35, 44, 46, 56, 66, 89, 92, 121, -1},
        {1, 10, 20, 37, 41, 52, 64, 69, 71, 114, -1},
        {8, 16, 56, 64, 93, 96, 101, 104, 117, 118, -1},
        {1, 13, 18, 34, 36, 63, 77, 84, 108, 119, -1},
        {3, 17, 32, 74, 82, 86, 90, 92, 104, 107, -1},
        {4, 22, 33, 38, 65, 73, 79, 95, 99, 109, -1},
        {18, 19, 65, 71, 80, 81, 83, 93, 98, 107, -1},
        {19, 53, 66, 87, 95, 102, 106, 113, 115, 116, -1},
        {14, 21, 23, 67, 70, 87, 89, 97, 104, 108, -1},
        {34, 52, 59, 67, 78, 90, 99, 116, 121, 127, -1},
        {4, 15, 18, 23, 46, 55, 74, 91, 105, 115, -1},
        {13, 28, 37, 47, 74, 79, 98, 100, 112, 118, -1},
        {1, 11, 55, 62, 70, 80, 92, 99, 111, 124, -1},
        {3, 30, 42, 93, 97, 106, 109, 119, 120, 121, -1},
        {1, 5, 32, 43, 49, 54, 58, 60, 97, 112, -1},
        {7, 32, 51, 70, 94, 95, 114, 118, 122, 123, -1},
        {9, 17, 25, 47, 55, 68, 76, 78, 93, 110, -1},
        {7, 28, 35, 36, 39, 40, 49, 55, 85, 117, -1},
        {10, 31, 38, 54, 80, 88, 91, 108, 118, 127, -1},
        {11, 24, 41, 58, 63, 74, 85, 88, 95, 120, -1},
        {3, 14, 37, 38, 43, 59, 61, 62, 103, 110, -1},
        {3, 6, 11, 13, 60, 66, 68, 81, 123, 127, -1},
        {2, 8, 15, 17, 31, 43, 79, 81, 120, 124, -1},
        {4, 21, 24, 40, 45, 59, 66, 72, 93, 114, -1},
        {20, 21, 22, 28, 31, 32, 48, 53, 77, 78, -1},
        {5, 23, 50, 68, 71, 88, 90, 103, 111, 117, -1},
        {6, 14, 29, 33, 57, 69, 82, 83, 91, 112, -1},
        {6, 8, 12, 22, 41, 49, 59, 76, 87, 92, -1},
        {9, 30, 37, 40, 60, 83, 84, 88, 89, 116, -1},
        {9, 13, 22, 24, 52, 54, 57, 96, 115, 125, -1},
        {0, 9, 15, 20, 56, 58, 72, 87, 98, 99, -1},
        {1, 21, 33, 56, 68, 100, 102, 107, 120, 125, -1},
        {17, 35, 41, 45, 48, 83, 96, 102, 111, 122, -1},
        {8, 34, 57, 70, 71, 72, 75, 85, 86, 106, -1},
        {3, 16, 25, 28, 44, 65, 72, 84, 111, 115, -1},
        {2, 28, 29, 46, 67, 71, 73, 76, 123, 125, -1},
        {6, 38, 46, 72, 78, 97, 100, 117, 122, 126, -1},
        {16, 34, 35, 42, 60, 79, 91, 94, 110, 125, -1},
        {7, 20, 23, 47, 57, 60, 61, 73, 92, 113, -1},
        {12, 43, 44, 45, 55, 57, 63, 100, 101, 116, 123, -1},
        {0, 5, 10, 16, 18, 45, 67, 85, 124, 126, -1},
        {18, 25, 30, 39, 61, 75, 99, 102, 104, 123, -1},
        {5, 29, 36, 47, 81, 89, 101, 102, 109, 114, -1},
        {2, 7, 9, 14, 27, 48, 63, 80, 106, 126, -1},
        {0, 2, 21, 41, 44, 75, 110, 113, 118, 119, -1},
        {26, 30, 51, 66, 73, 77, 110, 112, 117, 124, -1},
        {5, 11, 14, 17, 22, 39, 64, 98, 116, 119, -1},
        {19, 26, 31, 61, 63, 64, 70, 82, 109, 125, -1},
        {13, 42, 50, 51, 53, 56, 61, 76, 83, 85, -1},
        {16, 23, 33, 36, 37, 51, 58, 80, 86, 121, -1},
        {8, 39, 48, 65, 69, 88, 100, 105, 113, 121, -1},
        {0, 19, 27, 33, 42, 49, 62, 74, 96, 127, -1},
        {31, 42, 75, 84, 87, 90, 105, 112, 114, 126, -1},
        {19, 24, 43, 69, 76, 77, 86, 89, 94, 126, -1},
        {6, 39, 45, 50, 58, 73, 94, 106, 107, 108, -1},
        {40, 44, 50, 52, 62, 91, 104, 109, 122, -1},
        {15, 25, 26, 35, 62, 69, 90, 95, 101, 108, -1},
        {12, 24, 27, 29, 30, 32, 64, 79, 105, 111, -1},
        {0, 4, 12, 25, 48, 51, 52, 81, 82, 97, -1},
        {7, 26, 38, 53, 67, 68, 86, 96, 105, 119, -1},
        {2, 12, 20, 26, 36, 103, 107, 115, 122, 127, -1}
};

        
constexpr bool c_g_matrix[c_check_bits][c_message_bits] =
{
        { 1,0,0,0,0,0,0,0,1,1,0,1,0,0,0,1,1,1,0,0,0,1,1,0,0,1,0,1,1,0,0,1,1,0,0,1,1,1,0,1,1,0,1,0,1,1,0,0,1,0,1,1,1,0,1,0,1,0,0,1,1,1,1,1},
        { 0,0,1,0,0,1,1,0,1,1,1,1,0,0,0,1,0,0,0,1,1,1,0,0,1,0,1,1,1,0,0,1,0,1,0,0,0,0,0,1,1,1,1,0,1,1,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1},
        { 0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,1,0,1,1,0,0,1,1,1,0,0,0,1,0,1,0,1,0,1,1,0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,1,1,0,1,1,0,1},
        { 0,1,0,0,0,0,0,0,1,0,1,0,0,1,1,0,1,1,0,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,1,0,1,1,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,1},
        { 1,0,1,0,1,1,0,0,0,1,1,0,1,1,0,1,0,1,1,0,1,1,1,1,0,1,1,0,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,1,1,1,1,0,1,0,0,0,1,0,0,1,1,1,0,0,1},
        { 1,1,0,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,0,1,1,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,0,1,1,0,0,1,0,1,0,0,0,1,1,1,0,1,0,0,1},
        { 0,1,1,1,1,0,1,1,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,1,0,1,0,1,1,1,1,1,0,0,0,0,0,1,1,0,0,1,0,1,1,1,1,0,0,0,1,0,1,0,0,1,0,1,1,1},
        { 1,1,1,1,0,1,1,0,1,1,0,1,0,1,0,1,1,0,0,1,1,1,0,0,0,1,0,0,0,0,1,1,0,0,1,0,1,0,1,0,1,1,0,1,1,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1},
        { 1,1,1,1,0,0,0,1,0,0,0,0,0,1,1,0,1,1,0,1,1,0,1,0,1,0,0,1,1,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,1,0,1,0,1,0,0,0,0,1,0,1,1,0,1,0,0,1,0},
        { 0,0,0,1,1,0,1,1,0,1,0,0,1,1,0,1,0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,1,0},
        { 0,1,0,1,1,0,1,0,0,1,0,0,1,1,0,1,1,1,1,0,0,0,1,1,1,0,1,1,0,1,0,1,1,0,0,0,1,0,1,0,0,0,1,1,1,0,0,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,1,0},
        { 1,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,1,1,1,1,0,1,1,1,0,0,1,0,0,0,0,0,0,1,0,1,1,1,1,1,0,1,0,1,0,0,1,1,0,1,0,0,0,1},
        { 1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1,0,1,0,1,1,1,0,1,1,0,1,0,1,0,1,1,0,0,0,1,0,1,1,1,1,0,1,1,0,1,0,0,1,1},
        { 0,0,0,0,1,0,1,1,0,0,0,0,1,1,0,1,1,1,0,1,1,1,1,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,0,1,0,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,0,0,1,0,1},
        { 0,1,1,1,1,0,1,1,0,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,1,1,1,0,0,1,0,0,0,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,1,1,1},
        { 0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,1,0,1,1,1,1,0,0,0,1},
        { 1,1,1,0,1,0,0,0,1,0,0,1,0,1,0,0,0,0,0,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,1,0,0,0,1,0,1,1,1,0,0,0,1,0,0,0,0,1,0,0,1,1,1,0,1},
        { 0,0,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,0,1,0,0,1,0,0,0,1,1,1,0,1,1,1,1,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,0,0,0,1},
        { 1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,0,1,1,1,1,1,0,1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,1,1,1,0,0,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1},
        { 1,0,0,1,1,1,0,0,0,1,1,1,0,1,1,0,1,1,0,0,1,0,1,0,0,0,1,1,1,0,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,1,1,0,1,0,1,0,0,1,1,0,0,1,0,1,1,0,0,1},
        { 1,1,1,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0,0,1,0,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,1,0,0},
        { 0,0,1,1,1,1,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,1,1,1,0,1,0,1,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,1,1,0,1,0,1,1,0,1,1,0,1,0,0,1},
        { 1,0,0,1,0,1,0,0,1,1,1,0,1,0,0,1,0,0,1,1,1,1,0,1,0,1,0,0,0,0,0,1,1,0,1,1,0,0,0,1,0,1,1,0,0,1,1,1,1,0,1,0,0,1,1,1,0,1,0,0,1,0,1,1},
        { 1,1,0,1,1,0,0,1,1,1,0,1,0,1,0,0,0,1,0,1,1,0,0,0,0,0,1,0,0,1,1,1,1,0,1,1,1,0,0,1,1,0,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0},
        { 1,0,0,1,0,0,1,1,1,0,1,0,0,0,0,0,1,1,1,0,1,0,0,0,0,1,1,0,1,1,1,1,1,0,0,1,1,0,1,1,0,1,0,1,0,0,1,1,0,1,1,1,0,0,1,1,0,1,1,1,0,1,1,0},
        { 1,1,0,1,0,1,1,0,1,1,1,0,0,1,1,1,0,0,0,1,0,0,1,0,1,1,1,0,1,1,1,1,0,0,0,1,1,0,1,0,1,0,0,0,1,1,1,0,0,1,1,1,0,1,0,0,0,0,1,0,1,1,1,0},
        { 1,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0,1,1,1,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,1,1},
        { 1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,1,0,1,1,0,0,1,0,0,0,0,0},
        { 0,0,1,1,1,1,0,1,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0,0,0,1,1,0,0,1,0,1,0,0,1,0,1,0,1,1,1,0,1,0,0,1,0,1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1},
        { 0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,0,1,0,0,1,0,1,1,1,0,1,0,1,0,0,1,1,1,1,1,1,0,1,0,1,0,1,1,1,0,0,0,1,1,0,0,0,0,0,1,0,0,1,0,0,1,0},
        { 0,1,1,1,0,1,0,1,1,1,1,1,0,1,1,0,1,0,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,0},
        { 1,0,1,0,0,0,1,1,0,1,0,0,0,0,0,1,0,1,0,0,0,1,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,1,1,1,1,0,0,0,1,0,1,1,0,0,0,1,1,1,1,0,0,0,1,0,0,0,1,0},
        { 1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,1,0,1,0,1,1,1,1,0,0,1,1,0,1,1,1,0,1,0,0,0,1,1,0,1,0,1,0,0,0,0,0,1,1,1,0,0,1,1,0,0,1,1},
        { 1,0,0,0,0,0,1,0,0,0,1,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,0,1,1,1,0,1,0,0,1,0,1,0,1,0,0,1,0,0,1,1,1,1,0,1,1,0,0,0,1,0,0,0,0,0},
        { 0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,1,1,0,1,0,0,1,1,1,1},
        { 0,1,1,1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,0,0,0,0,0,1,1,0,1,0,1,0,0,1,1,1,1,0,1,1,0,0,0,0,0,0,0},
        { 1,1,0,0,0,0,0,1,0,0,1,1,1,0,1,0,0,1,1,0,1,0,0,1,1,0,0,0,1,0,0,1,1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,0,1,0,1,1,0,0,0,1},
        { 0,0,1,1,1,0,0,0,1,0,1,0,0,1,0,0,1,1,0,1,0,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,1,0,1,0,1,1,0,1,1,0,0,0,0},
        { 0,1,1,1,0,1,0,1,1,1,1,0,0,1,1,0,1,0,0,1,1,0,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0},
        { 1,0,0,0,1,0,0,1,1,0,1,0,0,1,1,0,0,0,1,0,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0},
        { 1,1,0,0,0,1,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,0,0,1,1,0,0,1,0,0,1,0,0,0,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,0,1,1,0,1},
        { 0,1,1,0,1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,0,1,0,1,1,0,0,0,1,1,1,0,1,1,0,0,0,0,0,1,1,0,1,0,0,0,0,1,1,1,1,0,1,0,0,1,1,0,0,0,0,1,0},
        { 1,1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,1,0,1,1,1,0,0,1,0,1,1,0,1,1,0,0,0,1,1,1,0,1,1,0,1,0,1,1,1,1,1,0,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1},
        { 0,0,1,0,0,0,1,1,1,1,1,0,1,0,0,1,0,1,1,0,0,1,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1},
        { 1,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0,0,1,0,1,1,1,0,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1,1,1,1,0,0,1,1,1,1,0,0,1,0,1,0,1,0,1},
        { 0,1,0,1,0,1,1,1,0,0,0,1,1,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,0,0,0,0,1,0,0,0,0,1,1,1,0,0,1},
        { 0,1,0,1,1,0,1,0,1,0,0,0,0,1,0,1,1,1,1,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,1,0,0,0,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,1,0,1,0,0,1,0},
        { 1,0,1,0,0,0,1,0,0,1,0,1,0,1,1,1,0,0,0,0,1,0,0,0,1,1,1,0,1,1,1,1,0,1,0,1,0,0,1,0,1,1,0,1,1,1,0,0,0,1,1,1,1,1,0,1,0,0,0,1,1,0,0,1},
        { 0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,0,1,1,0,1,1,0,0,0,1,0,0,0,0,1,1,1,0},
        { 1,0,1,1,1,1,0,0,0,1,0,1,0,1,0,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,0,0,1,0,1,1,1,1,0,0,0,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,0,1,1,1,1,0},
        { 0,1,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1,1,0,1,0,1,0,0,1,1,0,0,0,1,1,1,0,1,1,1,1,0,0,1,1,1,0,0,1,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0},
        { 0,1,1,1,0,0,1,1,0,1,0,1,0,0,1,1,1,0,0,1,0,0,0,1,0,0,1,0,0,1,1,0,0,0,1,1,1,1,1,1,0,1,0,0,0,0,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1},
        { 1,1,1,1,0,0,0,1,0,1,1,0,1,0,1,1,0,0,1,1,1,0,1,1,1,1,1,1,1,0,1,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,0,1,0,0,0,1,0,0,1},
        { 0,1,1,1,1,0,1,0,0,1,0,0,1,1,0,1,1,1,1,0,0,0,1,0,1,0,1,1,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,1,0,1,1,0,0,0,0,1,0,0,0,0,1,1,0},
        { 1,1,1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,0,0,1,1,0,0,0,1,0,1,0,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0,1,1,1,0,1,0,1,0,0,0,1,1,1,1},
        { 1,0,0,0,0,1,0,1,0,0,1,0,1,1,0,0,0,1,1,1,0,0,1,1,0,1,0,0,0,1,1,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,1,0,0},
        { 0,0,0,0,0,0,1,1,1,0,0,0,1,0,1,1,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,1,1,1,0,1,0,0,0,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,0,0,1,1,1,1,1,1},
        { 1,1,0,0,1,1,1,1,0,0,1,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,0,0,0,0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0},
        { 1,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,1,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,1,1,1,1,1,0,0,1,0,1,0,1,0,1,1,0,1,0,1,1,0,0,0,1,1,1},
        { 1,0,1,0,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,0,0,0,0,1,1,0,1,0,1,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,0,0,0,1,0,0,0},
        { 0,0,0,0,1,0,0,1,0,1,1,0,0,0,0,0,1,0,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,0,1,0,1,1,0,0,1,0,0,1,1,1,0,0,0,0,1,0,1,0,0,1,1,1,1,0,1,0},
        { 1,0,1,0,0,0,1,1,1,1,0,0,1,0,1,1,1,1,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0,1,0,1,1,1,0,1,1,0,0,1,1,1,1,0,1},
        { 1,0,1,0,1,1,1,0,1,0,0,0,1,1,0,0,0,0,1,0,1,1,1,0,1,0,0,1,1,0,0,0,1,0,1,0,1,1,1,1,0,0,0,1,1,0,1,0,0,1,1,0,1,0,1,1,0,1,0,0,0,1,0,1},
        { 0,0,0,0,1,1,0,1,1,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,1,0,1,0,0,1,1,1,0,1,0,0,1,1,0,0,0,1,1,1,0,1,1,0,1,1,1,1,1,0,1,0}
};

//message bits at end!
//in the example below it shows that codeword_to_transfer[c_g_matrix_column_order[0]] = original_codeword[0],
// codeword_to_transfer[c_g_matrix_column_order[1]] = original_codeword[1] ... so on
//original codeword consist of multiplied message at g (first c_check_bits) and the message bits itself (last c_message_bits)
constexpr int c_g_matrix_column_order[c_num_h_columns] = {
        4, 11, 34, 10,  1,  8, 13,  3, 22, 18, 19, 14, 40, 15, 20, 23, 17,  5,  7,  9,
        28, 27, 24, 21,  6, 16, 30, 33, 29, 32, 31, 25, 35,  2,  0, 36, 37, 39, 42, 12,
        38, 41, 43, 44, 45, 46, 47, 48, 26, 52, 50, 58, 54, 53, 49, 55, 61, 57, 56, 59,
        67, 51, 63, 62, 64, 65, 66, 60, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
        80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
        100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,
        120,121,122,123,124,125,126,127
};
        
} //ldpc
