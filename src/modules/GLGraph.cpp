// Copyright 2004 "Gilles Degottex"

// This file is part of "Music"

// "Music" is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation; either version 2.1 of the License, or
// (at your option) any later version.
//
// "Music" is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA


#include "GLGraph.h"

static const unsigned char g_icon_graph[] = {
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
    0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20,
    0x08, 0x06, 0x00, 0x00, 0x00, 0x73, 0x7a, 0x7a, 0xf4, 0x00, 0x00, 0x07,
    0xa8, 0x49, 0x44, 0x41, 0x54, 0x78, 0x9c, 0xad, 0x97, 0x6b, 0x6c, 0x14,
    0xd7, 0x15, 0xc7, 0x7f, 0x33, 0x3b, 0x3b, 0x6b, 0xef, 0xfa, 0xbd, 0xeb,
    0xe7, 0x62, 0x13, 0xec, 0xb5, 0x8d, 0x63, 0xb0, 0x0d, 0xc8, 0x50, 0x88,
    0x81, 0xa4, 0x22, 0x98, 0x12, 0x20, 0x69, 0xd2, 0x22, 0x85, 0xa6, 0x4a,
    0xda, 0xa8, 0x1f, 0xac, 0x44, 0x0a, 0x1f, 0x88, 0x54, 0x91, 0x22, 0x5a,
    0xb5, 0x11, 0x52, 0x95, 0x3e, 0x48, 0x9b, 0x5a, 0xad, 0x1a, 0xa5, 0x2d,
    0xb4, 0x5f, 0xa2, 0x96, 0x52, 0x68, 0x8b, 0x6d, 0x5e, 0x06, 0x1b, 0x53,
    0xbc, 0x7e, 0x61, 0x83, 0xb1, 0xc1, 0x76, 0xfc, 0xc0, 0xe0, 0xc7, 0xda,
    0xde, 0x5d, 0x7b, 0xbd, 0xbb, 0xde, 0x99, 0xdb, 0x0f, 0x6b, 0x90, 0x31,
    0x36, 0x21, 0x88, 0x23, 0x8d, 0xae, 0x34, 0x9a, 0x7b, 0xfe, 0xbf, 0x7b,
    0xce, 0x3d, 0xf7, 0x9e, 0x91, 0x78, 0x0c, 0xb3, 0x95, 0x94, 0xa5, 0x03,
    0xdf, 0x04, 0x26, 0x81, 0x11, 0xa0, 0x6e, 0xb4, 0xa6, 0x7c, 0xf4, 0x71,
    0xe6, 0x7e, 0x99, 0x49, 0x8f, 0x21, 0xfe, 0x36, 0x50, 0x0e, 0x18, 0xe7,
    0xbc, 0x16, 0x40, 0x33, 0x70, 0x7a, 0xf6, 0xb9, 0x38, 0x5a, 0x53, 0x3e,
    0xfd, 0xd4, 0x01, 0x6c, 0x25, 0x65, 0xd1, 0x40, 0x37, 0x60, 0x7b, 0xef,
    0x8d, 0x52, 0x36, 0xae, 0xc9, 0x65, 0xca, 0xe7, 0xa7, 0xf5, 0xe6, 0x00,
    0x57, 0x3b, 0xfb, 0x68, 0x6a, 0xef, 0x65, 0x64, 0xdc, 0x0b, 0x10, 0x00,
    0x2e, 0xcd, 0x01, 0xaa, 0x1f, 0xad, 0x29, 0x17, 0x4f, 0x03, 0xe0, 0x20,
    0xf0, 0xe3, 0x6f, 0x6c, 0x2c, 0xe4, 0xf0, 0x07, 0x6f, 0xd3, 0x75, 0x37,
    0x80, 0xa6, 0x0b, 0x22, 0x8c, 0x12, 0xb6, 0x18, 0x23, 0xd6, 0x28, 0x03,
    0x4d, 0xed, 0x3d, 0x1c, 0x3f, 0xdb, 0xc0, 0xc9, 0xea, 0x26, 0x86, 0x5c,
    0x9e, 0x7b, 0x53, 0xef, 0x00, 0xff, 0x04, 0x8e, 0x01, 0xe7, 0x47, 0x6b,
    0xca, 0x67, 0xbe, 0x32, 0x80, 0xad, 0xa4, 0x2c, 0x01, 0xf8, 0x42, 0x35,
    0x2a, 0xd1, 0x15, 0x9f, 0x1e, 0x60, 0x64, 0xca, 0x84, 0xa6, 0x0b, 0x74,
    0x5d, 0xa0, 0x0b, 0xd0, 0x05, 0x08, 0x01, 0x31, 0x91, 0x32, 0xd6, 0x68,
    0x23, 0xd6, 0x68, 0x99, 0x5b, 0xdd, 0xbd, 0x9c, 0xa8, 0x6e, 0xe2, 0xc4,
    0xf9, 0x26, 0x86, 0xc7, 0xee, 0xc3, 0x8c, 0x03, 0x27, 0x67, 0x61, 0x2a,
    0x46, 0x6b, 0xca, 0x7d, 0x8f, 0x0b, 0xb0, 0x17, 0xf8, 0xd5, 0xde, 0xef,
    0x96, 0xf2, 0xf2, 0xb6, 0x17, 0x99, 0xf0, 0x69, 0x08, 0x21, 0x10, 0x3a,
    0xe8, 0x22, 0x0c, 0x31, 0x13, 0x0a, 0xd1, 0xd1, 0xd3, 0x48, 0x63, 0xdb,
    0x19, 0x84, 0x26, 0x78, 0xe5, 0xc5, 0x77, 0x49, 0x4b, 0x8e, 0x27, 0x29,
    0xc6, 0x40, 0xff, 0x40, 0x3f, 0xff, 0xae, 0x6e, 0xe4, 0x64, 0x75, 0xf3,
    0x5c, 0x18, 0x1f, 0x70, 0x70, 0xb4, 0xa6, 0xfc, 0xa3, 0xc7, 0x01, 0x68,
    0x31, 0xa9, 0x4a, 0x41, 0xe3, 0xe7, 0x87, 0xe8, 0x1f, 0x0f, 0x8b, 0x0a,
    0x01, 0xb7, 0x87, 0x7b, 0xa8, 0x6f, 0x3d, 0xc7, 0x95, 0x96, 0x2a, 0x6e,
    0x0e, 0x3a, 0x29, 0x7c, 0x21, 0x85, 0x8c, 0x3c, 0x1b, 0xc7, 0x7e, 0xd7,
    0xcc, 0x81, 0xd7, 0x3f, 0x27, 0x2b, 0x6f, 0x15, 0xba, 0x1e, 0x4e, 0x7f,
    0x7c, 0x94, 0x42, 0x6a, 0xbc, 0x42, 0x5f, 0x7f, 0x1f, 0xff, 0x38, 0xed,
    0xe4, 0xc8, 0x89, 0x5a, 0x74, 0x5d, 0x17, 0x7a, 0x60, 0x32, 0x67, 0xdc,
    0x79, 0xf4, 0x16, 0x80, 0xb2, 0x88, 0xf8, 0x2a, 0xa0, 0x60, 0xd7, 0x0b,
    0xab, 0x99, 0x0a, 0x04, 0xb8, 0xdc, 0x72, 0x96, 0xba, 0xc6, 0x4a, 0x2e,
    0xb7, 0x9d, 0x25, 0x7e, 0x99, 0x46, 0xd1, 0xc6, 0x65, 0xe4, 0xbd, 0x6e,
    0x24, 0xdb, 0x9c, 0x4f, 0x47, 0xd7, 0x38, 0x75, 0x93, 0x5d, 0x88, 0xf4,
    0x20, 0x2d, 0xd7, 0xab, 0x58, 0xbe, 0xa2, 0x08, 0x49, 0x91, 0xd1, 0x75,
    0x81, 0x77, 0x5a, 0xc3, 0x33, 0xad, 0x11, 0x13, 0x95, 0xc6, 0x2f, 0xde,
    0xdf, 0xc3, 0x90, 0xcb, 0x4d, 0x45, 0x6d, 0xab, 0x34, 0xd5, 0x53, 0xbb,
    0x12, 0xe8, 0x01, 0xb4, 0x05, 0x01, 0x80, 0xef, 0x01, 0xbc, 0xb9, 0x6b,
    0x23, 0xdb, 0xdf, 0x59, 0xcf, 0x92, 0x62, 0x23, 0x39, 0x9b, 0x53, 0x79,
    0xe9, 0x15, 0x07, 0xb7, 0x3d, 0x6e, 0x1a, 0xda, 0x5d, 0x84, 0x9a, 0x55,
    0x42, 0x9e, 0x19, 0x3c, 0x2e, 0x17, 0x5f, 0x7b, 0x35, 0x15, 0x77, 0x9e,
    0x87, 0xab, 0x97, 0x6b, 0xd9, 0xe5, 0xfe, 0x3e, 0x71, 0xb6, 0x24, 0x74,
    0x21, 0x21, 0x66, 0x53, 0x65, 0x36, 0xc9, 0x00, 0x74, 0xf5, 0x0f, 0x23,
    0x74, 0xcd, 0x1b, 0x1c, 0xeb, 0xd5, 0x00, 0x0b, 0xe0, 0x79, 0x08, 0xc0,
    0x56, 0x52, 0xa6, 0x02, 0x7b, 0x72, 0x9f, 0x49, 0xa5, 0x30, 0x6f, 0x19,
    0x2b, 0xb2, 0x56, 0xe3, 0xd8, 0xe0, 0xe3, 0xd4, 0xdd, 0x56, 0x66, 0xaa,
    0xac, 0x04, 0xbd, 0xd3, 0xb8, 0x07, 0x87, 0x98, 0x1e, 0xf3, 0x12, 0x63,
    0x8e, 0x23, 0x2e, 0xca, 0xc6, 0xc8, 0x35, 0x0f, 0x11, 0xf9, 0x46, 0x3a,
    0x27, 0x9a, 0x19, 0x19, 0xea, 0x21, 0x29, 0x35, 0x05, 0x21, 0x08, 0x03,
    0xe8, 0x90, 0x12, 0xa7, 0x72, 0x7b, 0x68, 0x8c, 0x5b, 0x7d, 0x43, 0xe8,
    0x01, 0x6f, 0x03, 0x42, 0x17, 0x84, 0x4b, 0x77, 0xc1, 0x14, 0xec, 0x04,
    0xac, 0x6f, 0xbe, 0x5c, 0xc2, 0x74, 0x50, 0xa7, 0x64, 0xf5, 0x16, 0xfe,
    0x73, 0xf9, 0x30, 0xc9, 0xb9, 0x16, 0x2e, 0xd5, 0xb5, 0x62, 0xb7, 0x3e,
    0xc3, 0xd6, 0x9c, 0x9d, 0x14, 0xe7, 0x6f, 0x62, 0x65, 0xee, 0x5a, 0x50,
    0x65, 0x76, 0xff, 0xb0, 0x98, 0x95, 0x05, 0x4b, 0x18, 0x77, 0xf8, 0xb8,
    0xdc, 0x7c, 0x8a, 0x82, 0x55, 0xeb, 0x90, 0x0d, 0x06, 0x84, 0x90, 0x00,
    0x41, 0x42, 0x94, 0xc2, 0x9f, 0xcf, 0xb4, 0x01, 0x30, 0xe3, 0x1d, 0x6e,
    0x00, 0xa6, 0x1e, 0x05, 0xf0, 0x56, 0x84, 0x6a, 0xe4, 0xdb, 0xa5, 0xeb,
    0x98, 0x09, 0x09, 0x36, 0x15, 0x7f, 0x9d, 0x9f, 0xfd, 0xe5, 0x3d, 0x76,
    0x3c, 0xbf, 0x1a, 0x29, 0x52, 0x62, 0x55, 0x66, 0x31, 0x3f, 0xdd, 0xf7,
    0x5b, 0x64, 0xd9, 0x10, 0x5e, 0x25, 0xf0, 0xdc, 0xca, 0x52, 0xfa, 0xda,
    0xeb, 0x31, 0x2f, 0x57, 0x69, 0xac, 0xae, 0xc5, 0x3b, 0x36, 0x4c, 0x62,
    0x4a, 0x1a, 0x42, 0x40, 0x74, 0xa4, 0x82, 0x2c, 0x43, 0x45, 0xed, 0x55,
    0x84, 0x10, 0xba, 0x7f, 0xf0, 0x6a, 0x23, 0x30, 0x74, 0x4f, 0x4c, 0x9e,
    0x17, 0xfe, 0x58, 0x60, 0x6b, 0xe9, 0x73, 0x2b, 0x31, 0x47, 0x46, 0x22,
    0xcb, 0x12, 0xe9, 0xc9, 0xe9, 0xc4, 0x9b, 0x92, 0x71, 0x0f, 0xfb, 0x30,
    0xd9, 0x15, 0xba, 0xee, 0xde, 0x40, 0x0f, 0x05, 0x51, 0x0c, 0x12, 0x48,
    0x1a, 0xdd, 0x03, 0xed, 0x64, 0xa6, 0x67, 0x33, 0xe4, 0x74, 0x63, 0x4a,
    0x32, 0x72, 0x6b, 0xaa, 0x8d, 0xfe, 0xde, 0x0e, 0x8c, 0x06, 0x09, 0xa3,
    0x41, 0x22, 0xce, 0x62, 0x60, 0x6a, 0x3a, 0x40, 0x4d, 0x53, 0x27, 0x22,
    0xe4, 0xef, 0x08, 0x4d, 0x8e, 0x78, 0x81, 0xe1, 0x7b, 0x9a, 0xf3, 0x23,
    0xb0, 0x13, 0x50, 0x5f, 0xda, 0x5c, 0x44, 0x48, 0x13, 0x28, 0x86, 0xf0,
    0x61, 0xb3, 0x36, 0x7f, 0x3d, 0x5f, 0x74, 0x5f, 0x21, 0x22, 0xdd, 0x48,
    0x4f, 0x4d, 0x17, 0x53, 0x9e, 0x71, 0x24, 0x49, 0xe3, 0x8d, 0x1f, 0xed,
    0xa4, 0xb5, 0xbb, 0x91, 0x88, 0x25, 0x46, 0x88, 0x80, 0x19, 0xb7, 0x4e,
    0x44, 0x8e, 0x81, 0x0b, 0x8d, 0xff, 0xa5, 0xa4, 0x64, 0x33, 0x26, 0x55,
    0xc5, 0x62, 0x32, 0x70, 0xaa, 0xa6, 0x8d, 0x40, 0x30, 0x84, 0xe6, 0x1b,
    0x73, 0x02, 0x21, 0xc0, 0xb5, 0x18, 0xc0, 0x6b, 0xaa, 0x51, 0x61, 0xcb,
    0xfa, 0x15, 0x08, 0x21, 0xe8, 0xbf, 0xdb, 0xc3, 0x2f, 0x8f, 0x1c, 0xa2,
    0xfe, 0x7a, 0x1d, 0x21, 0x97, 0x17, 0xd3, 0x1a, 0x85, 0x89, 0x19, 0x0f,
    0x6d, 0x9d, 0x8d, 0xc4, 0x26, 0xc6, 0xd1, 0x3e, 0xdc, 0xcc, 0x89, 0xbf,
    0x9e, 0xe4, 0xba, 0xf7, 0x2a, 0x9f, 0xdc, 0xf8, 0x08, 0x81, 0xc0, 0x9c,
    0xa7, 0xd2, 0x54, 0x55, 0x83, 0xec, 0x77, 0x91, 0x9c, 0x94, 0x01, 0x40,
    0x45, 0x6d, 0x2b, 0x00, 0x81, 0xd1, 0x6e, 0x27, 0x30, 0x0a, 0xe8, 0x0f,
    0xa5, 0xc0, 0x56, 0x52, 0x16, 0x05, 0x6c, 0x7b, 0xbe, 0x38, 0x0f, 0x73,
    0x84, 0x09, 0x59, 0x96, 0xf8, 0xc1, 0x4f, 0xbe, 0x43, 0xde, 0xba, 0x2c,
    0xf6, 0xec, 0xdb, 0x8d, 0x65, 0x83, 0x19, 0xd5, 0x66, 0x40, 0x8e, 0x90,
    0xb8, 0x7e, 0xab, 0x01, 0x2d, 0x34, 0x89, 0x21, 0x56, 0xa6, 0x72, 0xe8,
    0x04, 0x7f, 0xef, 0xfd, 0x1b, 0x02, 0x81, 0xd0, 0x20, 0xe4, 0xd1, 0xb8,
    0x31, 0xdc, 0x4e, 0xcb, 0xf5, 0x16, 0x20, 0x5c, 0x09, 0x55, 0x75, 0x6d,
    0x08, 0x2d, 0xe4, 0xf2, 0xdf, 0x69, 0xeb, 0x99, 0x9b, 0xff, 0xf9, 0x11,
    0xd8, 0x0e, 0x44, 0xec, 0xd8, 0x5c, 0x84, 0x10, 0x00, 0x1a, 0x7d, 0xee,
    0x6e, 0x32, 0x97, 0x2f, 0xe3, 0xfc, 0x50, 0x15, 0x22, 0x26, 0x7c, 0x9f,
    0x98, 0xec, 0x06, 0x5a, 0xbb, 0x9b, 0xd9, 0xff, 0xce, 0x01, 0x62, 0x7f,
    0x1e, 0xcf, 0x1f, 0x0f, 0x7f, 0x8a, 0x92, 0xa8, 0x30, 0xe3, 0xd2, 0x08,
    0xf6, 0x87, 0x88, 0x56, 0x62, 0xd8, 0x9a, 0x5f, 0xca, 0xf8, 0x98, 0x8b,
    0x60, 0x30, 0xc8, 0xb5, 0xae, 0x41, 0x86, 0xc7, 0x3c, 0x68, 0x01, 0x8f,
    0x73, 0x56, 0x67, 0x78, 0x31, 0x80, 0x6f, 0x19, 0x0c, 0x32, 0xdb, 0x4a,
    0x0a, 0x00, 0x30, 0x1a, 0x14, 0xb2, 0x13, 0x72, 0x79, 0xff, 0x0f, 0x7b,
    0x51, 0x57, 0x4a, 0xc8, 0xaa, 0x44, 0x60, 0x20, 0x44, 0xc8, 0x23, 0xe8,
    0x98, 0xe8, 0x64, 0x7a, 0xca, 0x47, 0x65, 0x79, 0x35, 0x07, 0x3f, 0xde,
    0x8f, 0x3f, 0xe8, 0x47, 0x8d, 0x57, 0x29, 0x5c, 0x53, 0xc4, 0xda, 0x67,
    0xd7, 0x91, 0x9e, 0x9e, 0x41, 0x9a, 0xdd, 0x8e, 0xaa, 0xaa, 0x54, 0x5e,
    0x9a, 0x2d, 0x3f, 0xf7, 0x1d, 0x27, 0xe0, 0x06, 0xfc, 0x0f, 0x01, 0xd8,
    0x4a, 0xca, 0x22, 0x81, 0xed, 0x1b, 0x8a, 0xb2, 0x89, 0x8b, 0xb6, 0x20,
    0x84, 0x00, 0x49, 0xe2, 0xd7, 0xfb, 0x7e, 0xc3, 0x9e, 0xfd, 0xbb, 0xe9,
    0xbf, 0xd8, 0x8f, 0x84, 0x84, 0x2c, 0xc9, 0xe4, 0xda, 0x73, 0xd9, 0x90,
    0x57, 0x82, 0x7b, 0x62, 0x82, 0xcc, 0xac, 0x2c, 0x3e, 0x3b, 0x74, 0x14,
    0x8f, 0xdb, 0x8d, 0x24, 0x49, 0x98, 0x4c, 0x26, 0xcc, 0x16, 0xcb, 0x03,
    0x9b, 0x6a, 0xb6, 0xfc, 0x42, 0xd3, 0xb7, 0x9b, 0x5b, 0xe6, 0xaf, 0x7e,
    0x6e, 0x04, 0xb6, 0x01, 0x96, 0x1d, 0x9b, 0x8a, 0x40, 0x02, 0x59, 0x0a,
    0xdf, 0x51, 0x45, 0xcf, 0xae, 0xe6, 0xf4, 0x27, 0xd5, 0x34, 0x5d, 0x75,
    0x32, 0x39, 0xe9, 0xc5, 0x9e, 0x9c, 0x4e, 0x6c, 0x6c, 0x1c, 0x29, 0xa9,
    0xa9, 0xd8, 0x12, 0x13, 0xc3, 0x0e, 0x14, 0x85, 0x04, 0xab, 0x75, 0xbe,
    0x5f, 0x00, 0xee, 0x8c, 0x4c, 0xd0, 0x7a, 0x73, 0x00, 0x3d, 0xe8, 0x6b,
    0xd3, 0xfd, 0x1e, 0xff, 0xfc, 0xfc, 0xcf, 0x05, 0x78, 0x0d, 0x60, 0xfb,
    0xa6, 0xa2, 0x87, 0xae, 0xc7, 0x34, 0xbb, 0x9d, 0x34, 0xbb, 0x7d, 0x41,
    0x81, 0x2f, 0xb3, 0xca, 0x4b, 0xe1, 0xdd, 0xaf, 0xf9, 0x5c, 0x4e, 0x20,
    0x08, 0x4c, 0xcc, 0xff, 0x46, 0x9e, 0x3d, 0xfb, 0x77, 0x16, 0xaf, 0xc8,
    0x24, 0xc5, 0x16, 0xfb, 0x44, 0x42, 0x8b, 0xd9, 0xfd, 0xf2, 0x1b, 0xee,
    0x74, 0x12, 0x0e, 0xff, 0x43, 0x6d, 0x9a, 0x0c, 0x6c, 0x01, 0x62, 0x76,
    0x6c, 0x2e, 0x7a, 0xaa, 0xe2, 0xd3, 0x81, 0x20, 0x17, 0x1b, 0x3a, 0x10,
    0x5a, 0x70, 0x30, 0x30, 0x72, 0x73, 0x90, 0x05, 0xc2, 0x7f, 0x0f, 0xa0,
    0x18, 0xa0, 0x30, 0x37, 0xe3, 0xa9, 0x02, 0x5c, 0x70, 0xde, 0xc0, 0x1f,
    0x9c, 0x41, 0x9b, 0xf6, 0x34, 0x10, 0x5e, 0xf9, 0xc8, 0x62, 0x00, 0x21,
    0x80, 0xcf, 0x8e, 0x5d, 0xa0, 0x77, 0xf0, 0xa9, 0xb4, 0xfa, 0x00, 0x73,
    0xca, 0x6f, 0xa0, 0x1e, 0x18, 0x03, 0x16, 0x6c, 0x4c, 0x15, 0xe0, 0x4f,
    0x42, 0xd7, 0xca, 0x8e, 0x9f, 0x6b, 0xb4, 0x1f, 0x3f, 0xd7, 0x48, 0x7e,
    0x96, 0x9d, 0xc2, 0xdc, 0x0c, 0x0a, 0x72, 0x33, 0x28, 0xcc, 0xcd, 0x20,
    0xdf, 0x61, 0x27, 0xd2, 0xa4, 0x7e, 0x25, 0x71, 0x21, 0x04, 0x15, 0xb5,
    0xad, 0x08, 0xa1, 0xfb, 0x7d, 0x03, 0x4d, 0xd7, 0x58, 0x24, 0xfc, 0x30,
    0xdb, 0x13, 0x9a, 0x97, 0xae, 0x5b, 0x63, 0x4a, 0x74, 0x7c, 0x2c, 0x1b,
    0xcd, 0xb9, 0x92, 0x41, 0x79, 0xa0, 0xa6, 0x64, 0x59, 0x22, 0x67, 0x69,
    0x0a, 0x05, 0x39, 0x19, 0xb3, 0x60, 0xe9, 0xac, 0x70, 0x2c, 0x21, 0xca,
    0x1c, 0xb1, 0x28, 0xc0, 0xc5, 0x86, 0x0e, 0x5e, 0xdd, 0x7b, 0x18, 0xcd,
    0xef, 0xfd, 0xdf, 0xb8, 0xf3, 0xe8, 0x87, 0xc0, 0x79, 0xc0, 0xbb, 0x28,
    0xc0, 0xec, 0x58, 0x00, 0x64, 0x18, 0x63, 0xd3, 0xe2, 0x55, 0x5b, 0x96,
    0x43, 0xb1, 0x58, 0x1d, 0xb2, 0x29, 0x3a, 0x5b, 0x36, 0x46, 0x38, 0x24,
    0x59, 0x89, 0x7b, 0x60, 0x92, 0x24, 0x91, 0x95, 0x9e, 0x14, 0x06, 0xca,
    0x49, 0xbf, 0x3f, 0x46, 0x5b, 0x22, 0x99, 0x09, 0x69, 0xbc, 0xf5, 0xc1,
    0xef, 0xa9, 0xbc, 0xd4, 0x46, 0x60, 0xb4, 0xeb, 0x63, 0xef, 0x8d, 0xca,
    0x7f, 0x01, 0x67, 0x1e, 0x19, 0x81, 0x39, 0x96, 0x0c, 0xc4, 0x03, 0x71,
    0x40, 0x2c, 0xa0, 0x02, 0x18, 0xe3, 0x33, 0x6c, 0x26, 0xeb, 0x32, 0x87,
    0xc1, 0x6c, 0xcd, 0x96, 0x4d, 0x51, 0x8e, 0x30, 0x94, 0x21, 0x7a, 0xbe,
    0xb3, 0xcc, 0x25, 0x89, 0x04, 0x67, 0x34, 0x06, 0x86, 0xc6, 0xd0, 0x43,
    0xc1, 0xdb, 0xe3, 0xf5, 0x47, 0xde, 0x15, 0x5a, 0xb0, 0x0b, 0x68, 0x7d,
    0x5c, 0x80, 0xf9, 0x66, 0x9e, 0x05, 0x89, 0x9b, 0x03, 0x65, 0x04, 0x50,
    0xad, 0x99, 0xc9, 0x6a, 0xc2, 0x52, 0x87, 0xc1, 0x9c, 0x90, 0x6d, 0x30,
    0x59, 0x1c, 0x92, 0x12, 0xe9, 0x90, 0x64, 0xd9, 0x0c, 0x20, 0x74, 0x6d,
    0x72, 0x7a, 0xa0, 0xf9, 0x43, 0x5f, 0xdf, 0x95, 0x6b, 0x40, 0x2d, 0xe1,
    0x4d, 0xf8, 0x44, 0x00, 0x0b, 0x99, 0x65, 0x1e, 0x50, 0x2c, 0xa0, 0x80,
    0x24, 0x99, 0x12, 0x1d, 0xa9, 0x06, 0x73, 0x82, 0x35, 0x30, 0x72, 0xab,
    0x5b, 0xf3, 0xb9, 0xa6, 0x08, 0xff, 0xa2, 0x39, 0x1f, 0xe1, 0xeb, 0x89,
    0x00, 0x16, 0xf2, 0x31, 0x1f, 0x2a, 0x92, 0x70, 0xe3, 0x71, 0x9d, 0xf0,
    0x11, 0xbc, 0xa8, 0xfd, 0x1f, 0xbf, 0x8b, 0x3f, 0x6e, 0xf8, 0x00, 0xc8,
    0x03, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60,
    0x82
};

#include <iostream>
using namespace std;
#include <qtooltip.h>
#include <qimage.h>
#include <qboxlayout.h>
#include <qwidgetaction.h>
#include <GL/glut.h>
#include <Music/Music.h>
using namespace Music;

GLGraph::GLGraph(QWidget* parent)
: QGLWidget(parent)
, View(tr("Captured Sound"), this)
, m_skip(1)
, m_new_values(false)
{
	// settings
	QPixmap img;
	img.loadFromData(g_icon_graph, sizeof(g_icon_graph), "PNG");
	setting_show->setIcon(QIcon(img));
	setting_show->setChecked(true);

	setting_showWaveForm = new QAction(tr("Show Wave Form"), this);
	setting_showWaveForm->setCheckable(true);
	connect(setting_showWaveForm, SIGNAL(toggled(bool)), this, SLOT(update()));
	setting_showWaveForm->setChecked(true);
	m_popup_menu.addAction(setting_showWaveForm);

	setting_autoScale = new QAction(tr("Auto scale"), this);
	setting_autoScale->setCheckable(true);
	connect(setting_autoScale, SIGNAL(toggled(bool)), this, SLOT(update()));
	setting_autoScale->setChecked(false);
	m_popup_menu.addAction(setting_autoScale);

	QHBoxLayout* scaleFactorActionLayout = new QHBoxLayout(&m_popup_menu);

	QLabel* scaleFactorActionTitle = new QLabel(tr("Scale factor"), &m_popup_menu);
	scaleFactorActionLayout->addWidget(scaleFactorActionTitle);

	setting_spinScaleFactor = new QSpinBox(&m_popup_menu);
	setting_spinScaleFactor->setMinimum(1);
	setting_spinScaleFactor->setMaximum(1000);
	setting_spinScaleFactor->setSingleStep(10);
	setting_spinScaleFactor->setToolTip(tr("Scale factor"));
	setting_spinScaleFactor->setValue(1000);
	connect(setting_spinScaleFactor, SIGNAL(valueChanged(int)), this, SLOT(update()));
	scaleFactorActionLayout->addWidget(setting_spinScaleFactor);

	QWidget* scaleFactorActionWidget = new QWidget(&m_popup_menu);
	scaleFactorActionWidget->setLayout(scaleFactorActionLayout);

	QWidgetAction* scaleFactorAction = new QWidgetAction(&m_popup_menu);
	scaleFactorAction->setDefaultWidget(scaleFactorActionWidget);
	m_popup_menu.addAction(scaleFactorAction);

	QHBoxLayout* durationActionLayout = new QHBoxLayout(&m_popup_menu);

	QLabel* durationActionTitle = new QLabel(tr("Duration"), &m_popup_menu);
	durationActionLayout->addWidget(durationActionTitle);

	setting_spinDuration = new QSpinBox(&m_popup_menu);
	setting_spinDuration->setMinimum(20);
	setting_spinDuration->setMaximum(120000);
	setting_spinDuration->setSingleStep(100);
	setting_spinDuration->setToolTip(tr("Duration"));
	setting_spinDuration->setValue(10000);
	connect(setting_spinDuration, SIGNAL(valueChanged(int)), this, SLOT(update()));
	durationActionLayout->addWidget(setting_spinDuration);

	QWidget* durationActionWidget = new QWidget(&m_popup_menu);
	durationActionWidget->setLayout(durationActionLayout);

	QWidgetAction* durationAction = new QWidgetAction(&m_popup_menu);
	durationAction->setDefaultWidget(durationActionWidget);
	m_popup_menu.addAction(durationAction);

	QHBoxLayout* maxHeightActionLayout = new QHBoxLayout(&m_popup_menu);

	QLabel* maxHeightActionTitle = new QLabel(tr("Max height"), &m_popup_menu);
	maxHeightActionLayout->addWidget(maxHeightActionTitle);

	setting_spinMaxHeight = new QSpinBox(&m_popup_menu);
	setting_spinMaxHeight->setMinimum(10);
	setting_spinMaxHeight->setMaximum(100000);
	setting_spinMaxHeight->setSingleStep(1);
	setting_spinMaxHeight->setToolTip(tr("Max height"));
	setting_spinMaxHeight->setValue(50);
	maxHeightActionLayout->addWidget(setting_spinMaxHeight);

	QWidget* maxHeightActionWidget = new QWidget(&m_popup_menu);
	maxHeightActionWidget->setLayout(maxHeightActionLayout);

	QWidgetAction* maxHeightAction = new QWidgetAction(&m_popup_menu);
	maxHeightAction->setDefaultWidget(maxHeightActionWidget);
	m_popup_menu.addAction(maxHeightAction);
}

void GLGraph::save()
{
	s_settings->setValue("showWaveForm", setting_showWaveForm->isChecked());
	s_settings->setValue("autoScale", setting_autoScale->isChecked());
	s_settings->setValue("setting_spinScaleFactor", setting_spinScaleFactor->value());
	s_settings->setValue("spinDuration", setting_spinDuration->value());
	s_settings->setValue("spinMaxHeight", setting_spinMaxHeight->value());
}
void GLGraph::load()
{
	setting_showWaveForm->setChecked(s_settings->value("showWaveForm", setting_showWaveForm->isChecked()).toBool());
	setting_autoScale->setChecked(s_settings->value("autoScale", setting_autoScale->isChecked()).toBool());
	setting_spinScaleFactor->setValue(s_settings->value("setting_spinScaleFactor", setting_spinScaleFactor->value()).toInt());
	setting_spinDuration->setValue(s_settings->value("spinDuration", setting_spinDuration->value()).toInt());
	setting_spinMaxHeight->setValue(s_settings->value("spinMaxHeight", setting_spinMaxHeight->value()).toInt());
}
void GLGraph::clearSettings()
{
// 	cerr << "GLGraph::clearSettings" << endl;
	s_settings->remove("showWaveForm");
	s_settings->remove("autoScale");
	s_settings->remove("setting_spinScaleFactor");
	s_settings->remove("spinDuration");
	s_settings->remove("spinMaxHeight");
}

void GLGraph::initializeGL()
{
	// Set the clear color to white
	glClearColor(1.0, 1.0, 1.0, 0.0);

	// glShadeModel( GL_FLAT );
	glShadeModel(GL_SMOOTH);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glLoadIdentity();
}

void GLGraph::resizeGL( int w, int h )
{
	// Set the new viewport size
	glViewport(0, 0, (GLint)w, (GLint)h);

	// Choose the projection matrix to be the matrix
	// manipulated by the following calls
	glMatrixMode(GL_PROJECTION);

	// Set the projection matrix to be the identity matrix
	glLoadIdentity();

	// Define the dimensions of the Orthographic Viewing Volume
	glOrtho(0.0, w, 0.0, h, 0.0, 1.0);

	// Choose the modelview matrix to be the matrix
	// manipulated by further calls
	glMatrixMode(GL_MODELVIEW);

	update_maxs();
}

void GLGraph::addValue(double v)
{
	m_pending_queue.push_front(v);
	m_queue.push_front(v);

	m_new_values = true;
}
void GLGraph::clearValues()
{
	m_queue.clear();
	m_maxs.clear();
}
void GLGraph::refreshGraph()
{
	int max_size = getLength();
	m_skip = max_size/width();
	if(m_skip<1)	m_skip = 1;

	while(!m_pending_queue.empty() && int(m_pending_queue.size()) >= m_skip)
	{
		double smin = m_pending_queue.back();
		double smax = m_pending_queue.back();
		for(int i=0; i<m_skip; i++)
		{
			m_queue.push_front(m_pending_queue.back());
			smin = min(smin, m_pending_queue.back());
			smax = max(smax, m_pending_queue.back());
			m_pending_queue.pop_back();
		}
		m_maxs.push_front(make_pair(smin, smax));
	}

	// drop unused data
	while(!m_maxs.empty() && int(m_maxs.size())>=width())
		m_maxs.pop_back();

	// drop unused data
	while(!m_queue.empty() && int(m_queue.size())>max_size)
		m_queue.pop_back();

	m_new_values = false;
}

void GLGraph::update_maxs()
{
//	cerr << "GLGraph::update_maxs " << m_sampling_rate << endl;

	if(m_queue.empty())	return;

	m_maxs.clear();
	int max_size = getLength();
	m_skip = max_size/width();
	if(m_skip<1)	m_skip = 1;

	// drop unused data
	while(!m_queue.empty() && int(m_queue.size())>max_size)
		m_queue.pop_back();

	// computes maxs
	for(size_t j=0; j+m_skip<=m_queue.size(); j+=m_skip)
	{
		double smin, smax;
		smin = smax = m_queue[j+m_skip];
		for(size_t i=j; i<j+m_skip && i<m_queue.size(); i++)
		{
			smin = min(smin, m_queue[i]);
			smax = max(smax, m_queue[i]);
		}
		m_maxs.push_back(make_pair(smin, smax));
	}

	updateGL();
}

void GLGraph::base_paint(float graph_gray)
{
// 	cerr << "GLGraph::base_paint " << m_queue.size() << ":" << m_maxs.size() << endl;

// 	cerr<<"m_pending_queue="<<m_pending_queue.size()<<" m_queue="<<m_queue.size()<<" m_maxs="<<m_maxs.size()<<endl;

	int width = QGLWidget::width();

	// name
	string str = tr("Captured Sound").toStdString();
	glColor3f(0.75,0.75,0.75);
	glRasterPos2i(2, height()-14);
	for(size_t i = 0; i < str.size(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, (unsigned char)str[i]);

	if(setting_showWaveForm->isChecked() && !m_queue.empty())
	{
		// horiz line
		glBegin(GL_LINES);
		float gray = 0.8;
		glColor3f(gray, gray, gray);
		glVertex2i(0, height()/2);
		glVertex2i(width, height()/2);
		glEnd();

		m_queue_amplitude = 0.0;
		double scale_factor;
		if(setting_autoScale->isChecked())
		{
			if(m_skip<2)
				for(size_t i=0; i<m_queue.size(); i++)
					m_queue_amplitude = max(m_queue_amplitude, abs(m_queue[i]));
			else
				for(size_t i=0; i<m_maxs.size(); i++)
					m_queue_amplitude = max(m_queue_amplitude, max(-m_maxs[i].first,m_maxs[i].second));
			scale_factor = 1.0/m_queue_amplitude;
		}
		else
			scale_factor = 1000.0/setting_spinScaleFactor->value();

		// paint the noise treshold
		glBegin(GL_LINES);
		int y = int((1+m_treshold*scale_factor)*height()/2);
		glColor3f(1.0,1.0,1.0);
		glVertex2i(0, y);
		glColor3f(1.0,0.5,0.5);
		glVertex2i(width, y);
		y = int((1-m_treshold*scale_factor)*height()/2);
		glColor3f(1.0,1.0,1.0);
		glVertex2i(0, y);
		glColor3f(1.0,0.5,0.5);
		glVertex2i(width, y);
		glEnd();

		// paint the wave form
		glColor3f(graph_gray, graph_gray, graph_gray);
		if(m_skip<2)
		{
			glBegin(GL_LINE_STRIP);

			glVertex2i(width-1, int((m_queue[0]*scale_factor)*height()/2 + height()/2));
			float istep = float(width)/m_queue.size();
			for(size_t i=1; i<m_queue.size(); i++)
				glVertex2i(width-1-int(i*istep), int((m_queue[i]*scale_factor)*height()/2 + height()/2));

			glEnd();
		}
		else
		{
			glBegin(GL_LINES);
			for(size_t i=0; i<m_maxs.size(); i++)
			{
				int x = width-1-i;
				int ymin = int((m_maxs[i].first*scale_factor)*height()/2 + height()/2);
				int ymax = int((m_maxs[i].second*scale_factor)*height()/2 + height()/2);
				glVertex2i(x, ymin);
				glVertex2i(x, ymax);
			}
			glEnd();
		}
	}
}

void GLGraph::paintGL()
{
	if(m_new_values)
		refreshGraph();

	glClear(GL_COLOR_BUFFER_BIT);

	base_paint();

	glFlush();
}

