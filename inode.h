#ifndef INODE_H
#define INODE_H

#define EXT2_ROOT_INO 2         // Inode do Diretório Raiz
#define EXT2_S_IFSOCK 0xC000
#define EXT2_S_IFLNK  0xA000
#define EXT2_S_IFREG  0x8000
#define EXT2_S_IFBLK  0x6000
#define EXT2_S_IFDIR  0x4000
#define EXT2_S_IFCHR  0x2000
#define EXT2_S_IFIFO  0x1000

// Essa estrutura representa um inode. No EXT2, um inode é de 128 bytes.

typedef struct inode {
    //  Variável de 16 bits usado para indicar o formato do arquivo.
    //
    //  -- formato do arquivo --
    //  EXT2_S_IFSOCK   0xC000  socket
    //  EXT2_S_IFLNK    0xA000  symbolic link
    //  EXT2_S_IFREG    0x8000  regular file
    //  EXT2_S_IFBLK    0x6000  block device
    //  EXT2_S_IFDIR    0x4000  directory
    //  EXT2_S_IFCHR    0x2000  character device
    //  EXT2_S_IFIFO    0x1000  fifo
    uint16_t i_mode;

    // Variável de 32 bits indicando o tamanho do arquivo em bytes
    uint32_t i_size;

    // Variável de 32 bits que representa o tempo UNIX (número de segundos desde a 
    // época, 1º de janeiro de 1970) da última vez em que este inode foi acessado.
    uint32_t i_atime;

    // Variável de 16 bits que representa o número total de blocos reservados para 
    // conter dados desse inode, independentemente de esses blocos serem usados. 
    // Os números dos blocos estão contidos no vetor i_block.
    uint16_t i_blocks;

    // Vetor de 15 números de bloco (de 32 bits) apontando 
    // para os blocos contendo dados.  As primeiras 12 entradas 
    // no vetor contém os números dos blocos de dados
    // (ou seja, são entradas "diretas"). 
    uint32_t i_block[12];
    
} inode;

#endif // INODE_H