package com.bisu.serverlibrary;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;

class ReadElf {

    public static void readelf() {
        String path = "D:\\huyangTrunk\\MyApplication\\app\\build\\outputs\\apk\\debug\\app-debug\\lib\\armeabi-v7a\\libnative-lib.so";
        try {
            BufferedInputStream bis = new BufferedInputStream(new FileInputStream(path));
            try {

                int len = bis.available();
                byte []b = new byte[len];
                bis.read(b,0,len);
                Utils.parseHeader(b,0);
            }catch (IOException e) {
                e.printStackTrace();
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }


    public static class ElfType32 {
        public elf32_rel rel;
        public elf32_rela rela;
        public ArrayList<Elf32_Sym> symList = new ArrayList<Elf32_Sym>();
        public elf32_hdr hdr;//elf头部信息
        public ArrayList<elf32_phdr> phdrList = new ArrayList<elf32_phdr>();//可能会有多个程序头
        public ArrayList<elf32_shdr> shdrList = new ArrayList<elf32_shdr>();//可能会有多个段头
        public ArrayList<elf32_strtb> strtbList = new ArrayList<elf32_strtb>();//可能会有多个字符串值

        public ElfType32() {
            rel = new elf32_rel();
            rela = new elf32_rela();
            hdr = new elf32_hdr();
        }

        /**
         *  typedef struct elf32_rel {
         Elf32_Addr    r_offset;
         Elf32_Word    r_info;
         } Elf32_Rel;
         *
         */
        public class elf32_rel {
            public byte[] r_offset = new byte[4];
            public byte[] r_info = new byte[4];

            @Override
            public String toString(){
                return "r_offset:"+Utils.bytesToHexString(r_offset)+";r_info:"+Utils.bytesToHexString(r_info);
            }
        }

        /**
         *  typedef struct elf32_rela{
         Elf32_Addr    r_offset;
         Elf32_Word    r_info;
         Elf32_Sword   r_addend;
         } Elf32_Rela;
         */
        public class elf32_rela{
            public byte[] r_offset = new byte[4];
            public byte[] r_info = new byte[4];
            public byte[] r_addend = new byte[4];

            @Override
            public String toString(){
                return "r_offset:"+Utils.bytesToHexString(r_offset)+";r_info:"+Utils.bytesToHexString(r_info)+";r_addend:"+Utils.bytesToHexString(r_info);
            }
        }

        /**
         * typedef struct elf32_sym{
         Elf32_Word    st_name;
         Elf32_Addr    st_value;
         Elf32_Word    st_size;
         unsigned char st_info;
         unsigned char st_other;
         Elf32_Half    st_shndx;
         } Elf32_Sym;
         */
        public static class Elf32_Sym{
            public byte[] st_name = new byte[4];
            public byte[] st_value = new byte[4];
            public byte[] st_size = new byte[4];
            public byte st_info;
            public byte st_other;
            public byte[] st_shndx = new byte[2];

            @Override
            public String toString(){
                return "st_name:"+Utils.bytesToHexString(st_name)
                        +"\nst_value:"+Utils.bytesToHexString(st_value)
                        +"\nst_size:"+Utils.bytesToHexString(st_size)
                        +"\nst_info:"+(st_info/16)
                        +"\nst_other:"+(((short)st_other) & 0xF)
                        +"\nst_shndx:"+Utils.bytesToHexString(st_shndx);
            }
        }

        public void printSymList(){
            for(int i=0;i<symList.size();i++){
                System.out.println();
                System.out.println("The "+(i+1)+" Symbol Table:");
                System.out.println(symList.get(i).toString());
            }
        }

        //Bind字段==》st_info
        public static final int STB_LOCAL = 0;
        public static final int STB_GLOBAL = 1;
        public static final int STB_WEAK = 2;
        //Type字段==》st_other
        public static final int STT_NOTYPE = 0;
        public static final int STT_OBJECT = 1;
        public static final int STT_FUNC = 2;
        public static final int STT_SECTION = 3;
        public static final int STT_FILE = 4;
        /**
         * 这里需要注意的是还需要做一次转化
         *  #define ELF_ST_BIND(x)  ((x) >> 4)
         #define ELF_ST_TYPE(x)  (((unsigned int) x) & 0xf)
         */

        /**
         * typedef struct elf32_hdr{
         unsigned char e_ident[EI_NIDENT];
         Elf32_Half    e_type;
         Elf32_Half    e_machine;
         Elf32_Word    e_version;
         Elf32_Addr    e_entry;  // Entry point
         Elf32_Off e_phoff;
         Elf32_Off e_shoff;
         Elf32_Word    e_flags;
         Elf32_Half    e_ehsize;
         Elf32_Half    e_phentsize;
         Elf32_Half    e_phnum;
         Elf32_Half    e_shentsize;
         Elf32_Half    e_shnum;
         Elf32_Half    e_shstrndx;
         } Elf32_Ehdr;
         */
        public class elf32_hdr{
            public byte[] e_ident = new byte[16];
//            public byte[] e_type = new byte[2];
//            public byte[] e_machine = new byte[2];
//            public byte[] e_version = new byte[4];
//            public byte[] e_entry = new byte[4];
//            public byte[] e_phoff = new byte[4];
//            public byte[] e_shoff = new byte[4];
//            public byte[] e_flags = new byte[4];
//            public byte[] e_ehsize = new byte[2];
//            public byte[] e_phentsize = new byte[2];
//            public byte[] e_phnum = new byte[2];
//            public byte[] e_shentsize = new byte[2];
//            public byte[] e_shnum = new byte[2];
//            public byte[] e_shstrndx = new byte[2];
            public byte[] file_e_ident = new byte[4];
            public byte[] ei_class = new byte[1];
            public byte[] ei_data = new byte[1];
            public byte[] ei_version = new byte[1];
            public byte[] ei_osabi = new byte[1];
            public byte[] ei_abiversion = new byte[1];
            public byte[] ei_padding = new byte[6];
            public byte[] ei_size = new byte[1];



            public String toEIString(){
                return  "magic:"+ Utils.getString(file_e_ident)
                        +"\nei_class:"+Utils.bytesToHexString(ei_class)
                        +"\nei_data:"+Utils.bytesToHexString(ei_data)
                        +"\nei_version:"+Utils.bytesToHexString(ei_version)
                        +"\nei_osabi:"+Utils.bytesToHexString(ei_osabi)
                        +"\nei_abiversion:"+Utils.bytesToHexString(ei_abiversion)
                        +"\nei_padding:"+Utils.bytesToHexString(ei_padding)
                        +"\nei_size:"+Utils.bytesToHexString(ei_size);
//                        +"\ne_type:"+Utils.bytesToHexString(e_type)
//                        +"\ne_machine:"+Utils.bytesToHexString(e_machine)
//                        +"\ne_version:"+Utils.bytesToHexString(e_version)
//                        +"\ne_entry:"+Utils.bytesToHexString(e_entry)
//                        +"\ne_phoff:"+Utils.bytesToHexString(e_phoff)
//                        +"\ne_shoff:"+Utils.bytesToHexString(e_shoff)
//                        +"\ne_flags:"+Utils.bytesToHexString(e_flags)
//                        +"\ne_ehsize:"+Utils.bytesToHexString(e_ehsize)
//                        +"\ne_phentsize:"+Utils.bytesToHexString(e_phentsize)
//                        +"\ne_phnum:"+Utils.bytesToHexString(e_phnum)
//                        +"\ne_shentsize:"+Utils.bytesToHexString(e_shentsize)
//                        +"\ne_shnum:"+Utils.bytesToHexString(e_shnum)
//                        +"\ne_shstrndx:"+Utils.bytesToHexString(e_shstrndx);
            }
        }

        /**
         * typedef struct elf32_phdr{
         Elf32_Word    p_type;
         Elf32_Off p_offset;
         Elf32_Addr    p_vaddr;
         Elf32_Addr    p_paddr;
         Elf32_Word    p_filesz;
         Elf32_Word    p_memsz;
         Elf32_Word    p_flags;
         Elf32_Word    p_align;
         } Elf32_Phdr;
         */
        public static class elf32_phdr{
            public byte[] p_type = new byte[4];
            public byte[] p_offset = new byte[4];
            public byte[] p_vaddr = new byte[4];
            public byte[] p_paddr = new byte[4];
            public byte[] p_filesz = new byte[4];
            public byte[] p_memsz = new byte[4];
            public byte[] p_flags = new byte[4];
            public byte[] p_align = new byte[4];

            @Override
            public String toString(){
                return "p_type:"+ Utils.bytesToHexString(p_type)
                        +"\np_offset:"+Utils.bytesToHexString(p_offset)
                        +"\np_vaddr:"+Utils.bytesToHexString(p_vaddr)
                        +"\np_paddr:"+Utils.bytesToHexString(p_paddr)
                        +"\np_filesz:"+Utils.bytesToHexString(p_filesz)
                        +"\np_memsz:"+Utils.bytesToHexString(p_memsz)
                        +"\np_flags:"+Utils.bytesToHexString(p_flags)
                        +"\np_align:"+Utils.bytesToHexString(p_align);
            }
        }

        public void printPhdrList(){
            for(int i=0;i<phdrList.size();i++){
                System.out.println();
                System.out.println("The "+(i+1)+" Program Header:");
                System.out.println(phdrList.get(i).toString());
            }
        }

        /**
         * typedef struct elf32_shdr {
         Elf32_Word    sh_name;
         Elf32_Word    sh_type;
         Elf32_Word    sh_flags;
         Elf32_Addr    sh_addr;
         Elf32_Off sh_offset;
         Elf32_Word    sh_size;
         Elf32_Word    sh_link;
         Elf32_Word    sh_info;
         Elf32_Word    sh_addralign;
         Elf32_Word    sh_entsize;
         } Elf32_Shdr;
         */
        public static class elf32_shdr{
            public byte[] sh_name = new byte[4];
            public byte[] sh_type = new byte[4];
            public byte[] sh_flags = new byte[4];
            public byte[] sh_addr = new byte[4];
            public byte[] sh_offset = new byte[4];
            public byte[] sh_size = new byte[4];
            public byte[] sh_link = new byte[4];
            public byte[] sh_info = new byte[4];
            public byte[] sh_addralign = new byte[4];
            public byte[] sh_entsize = new byte[4];

            @Override
            public String toString(){
                return "sh_name:"+Utils.bytesToHexString(sh_name)/*Utils.byte2Int(sh_name)*/
                        +"\nsh_type:"+Utils.bytesToHexString(sh_type)
                        +"\nsh_flags:"+Utils.bytesToHexString(sh_flags)
                        +"\nsh_add:"+Utils.bytesToHexString(sh_addr)
                        +"\nsh_offset:"+Utils.bytesToHexString(sh_offset)
                        +"\nsh_size:"+Utils.bytesToHexString(sh_size)
                        +"\nsh_link:"+Utils.bytesToHexString(sh_link)
                        +"\nsh_info:"+Utils.bytesToHexString(sh_info)
                        +"\nsh_addralign:"+Utils.bytesToHexString(sh_addralign)
                        +"\nsh_entsize:"+ Utils.bytesToHexString(sh_entsize);
            }
        }

        /****************sh_type********************/
        public static final int SHT_NULL = 0;
        public static final int SHT_PROGBITS = 1;
        public static final int SHT_SYMTAB = 2;
        public static final int SHT_STRTAB = 3;
        public static final int SHT_RELA = 4;
        public static final int SHT_HASH = 5;
        public static final int SHT_DYNAMIC = 6;
        public static final int SHT_NOTE = 7;
        public static final int SHT_NOBITS = 8;
        public static final int SHT_REL = 9;
        public static final int SHT_SHLIB = 10;
        public static final int SHT_DYNSYM = 11;
        public static final int SHT_NUM = 12;
        public static final int SHT_LOPROC = 0x70000000;
        public static final int SHT_HIPROC = 0x7fffffff;
        public static final int SHT_LOUSER = 0x80000000;
        public static final int SHT_HIUSER = 0xffffffff;
        public static final int SHT_MIPS_LIST = 0x70000000;
        public static final int SHT_MIPS_CONFLICT = 0x70000002;
        public static final int SHT_MIPS_GPTAB = 0x70000003;
        public static final int SHT_MIPS_UCODE = 0x70000004;

        /*****************sh_flag***********************/
        public static final int SHF_WRITE = 0x1;
        public static final int SHF_ALLOC = 0x2;
        public static final int SHF_EXECINSTR = 0x4;
        public static final int SHF_MASKPROC = 0xf0000000;
        public static final int SHF_MIPS_GPREL = 0x10000000;

        public void printShdrList(){
            for(int i=0;i<shdrList.size();i++){
                System.out.println();
                System.out.println("The "+(i+1)+" Section Header:");
                System.out.println(shdrList.get(i));
            }
        }


        public static class elf32_strtb{
            public byte[] str_name;
            public int len;

            @Override
            public String toString(){
                return "str_name:"+str_name
                        +"len:"+len;
            }
        }
    }

    public static class Utils {

        public static ElfType32 type_32 = new ElfType32();

        /**
         * 解析Elf的头部信息
         *
         * @param header
         */
        public static void parseHeader(byte[] header, int offset) {
            if (header == null) {
                System.out.println("header is null");
                return;
            }
            /**
             *  public byte[] e_ident = new byte[16];
             public short e_type;
             public short e_machine;
             public int e_version;
             public int e_entry;
             public int e_phoff;
             public int e_shoff;
             public int e_flags;
             public short e_ehsize;
             public short e_phentsize;
             public short e_phnum;
             public short e_shentsize;
             public short e_shnum;
             public short e_shstrndx;
             */
            type_32.hdr.e_ident = Utils.copyBytes(header, 0, 16);//魔数

            type_32.hdr.file_e_ident = Utils.copyBytes(header, 0, 4);
            type_32.hdr.ei_class = Utils.copyBytes(header, 4, 1);
            type_32.hdr.ei_data = Utils.copyBytes(header, 5, 1);
            type_32.hdr.ei_version = Utils.copyBytes(header, 6, 1);
            type_32.hdr.ei_osabi = Utils.copyBytes(header, 7, 1);
            type_32.hdr.ei_abiversion = Utils.copyBytes(header, 8, 1);
            type_32.hdr.ei_padding = Utils.copyBytes(header, 9, 6);
            type_32.hdr.ei_size = Utils.copyBytes(header, 15, 1);
//            type_32.hdr.e_type = Utils.copyBytes(header, 16, 2);
//            type_32.hdr.e_machine = Utils.copyBytes(header, 18, 2);
//            type_32.hdr.e_version = Utils.copyBytes(header, 20, 4);
//            type_32.hdr.e_entry = Utils.copyBytes(header, 24, 4);
//            type_32.hdr.e_phoff = Utils.copyBytes(header, 28, 4);
//            type_32.hdr.e_shoff = Utils.copyBytes(header, 32, 4);
//            type_32.hdr.e_flags = Utils.copyBytes(header, 36, 4);
//            type_32.hdr.e_ehsize = Utils.copyBytes(header, 40, 2);
//            type_32.hdr.e_phentsize = Utils.copyBytes(header, 42, 2);
//            type_32.hdr.e_phnum = Utils.copyBytes(header, 44, 2);
//            type_32.hdr.e_shentsize = Utils.copyBytes(header, 46, 2);
//            type_32.hdr.e_shnum = Utils.copyBytes(header, 48, 2);
//            type_32.hdr.e_shstrndx = Utils.copyBytes(header, 50, 2);
            System.out.println(type_32.hdr.toEIString());
        }

        public static byte[] copyBytes(byte[] header, int i, int i1) {
            byte[] result = new byte[i1];
            System.arraycopy(header, i, result, 0, i1);
            return result;
        }


        public static String bytesToHexString(byte[] bArray) {
            StringBuffer sb = new StringBuffer(bArray.length);
            String sTemp;
            for (int i = 0; i < bArray.length; i++) {
                sTemp = Integer.toHexString(0xFF & bArray[i]);
                if (sTemp.length() < 2) {
                    sb.append(0);
                }

                sb.append(sTemp.toUpperCase());
            }
            return sb.toString();


        }

        public static String getString(byte[] file_e_ident) {
            String res = null;
            try {
                 res = new String(file_e_ident,"UTF-8");
            } catch (UnsupportedEncodingException e) {
                e.printStackTrace();
            }
            return res;
        }
    }

}
