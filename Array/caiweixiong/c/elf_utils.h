//
// Created by Vashon on 2020/7/1.
//

#ifndef C_ELF_UTILS_H
#define C_ELF_UTILS_H

#include <stdio.h>

// 运行Elf文件解析
void runElfParse(void);

// 检查文件是否 ELF 文件，不是则退出程序
void checkElfFile(FILE *file);

// 输出ELF文件信息
void printfElf32_Message(FILE *elf);

// 输出ELF头部的信息
void printfElf32_EhdrMessage(Elf32_Ehdr);

// 输出程序头部的信息
void printfElf32_PhdrMessage(FILE *, int, int);

// 输出节头部的信息
void printfElf32_ShdrMessage(FILE *, int, int, uint16_t);

// 获取节中的名称
void getSectionNameByName(uint32_t nameIndex, char srcName[], char destName[]);

// 获取节中的类型名称
void getSectionTypeNameByType(uint32_t type, char name[]);

// 获取节中的标记名称
void getSectionFlagNameByFlags(uint32_t flags, char flag[]);

// 获取段中的类型名称
void getSegmentTypeNameByType(uint32_t type, char name[]);

// 获取段中的标记名称
void getSegmentFlagNameByFlags(uint32_t flags, char flag[]);

#endif //C_ELF_UTILS_H
