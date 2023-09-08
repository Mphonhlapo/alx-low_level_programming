#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* Check if the given file is an ELF file. */
void check_elf(unsigned char *e_ident);

/* Print the ELF magic numbers. */
void print_magic(unsigned char *e_ident);

/* Print the ELF class. */
void print_class(unsigned char *e_ident);

/* Print the ELF data encoding. */
void print_data(unsigned char *e_ident);

/* Print the ELF version. */
void print_version(unsigned char *e_ident);

/* Print the ELF OS/ABI. */
void print_osabi(unsigned char *e_ident);

/* Print the ELF ABI version. */
void print_abi(unsigned char *e_ident);

/* Print the ELF file type. */
void print_type(unsigned int e_type, unsigned char *e_ident);

/* Print the ELF entry point. */
void print_entry(unsigned long int e_entry, unsigned char *e_ident);

/* Close the ELF file. */
void close_elf(int elf);

void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127)
		{
			fprintf(stderr, "Error: Not an ELF file\n");
			exit(98);
		}
		else if (e_ident[index] != 'E')
		{
			fprintf(stderr, "Error: Not an ELF file\n");
			exit(98);
		}
		else if (e_ident[index] != 'L')
		{
			fprintf(stderr, "Error: Not an ELF file\n");
			exit(98);
		}
		else if (e_ident[index] != 'F')
		{
			fprintf(stderr, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

void print_magic(unsigned char *e_ident)
{
	int index;

	printf(" Magic: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

void print_class(unsigned char *e_ident)
{
	printf(" Class: ");

	if (e_ident[EI_CLASS] == ELFCLASSNONE)
		printf("none\n");
	else if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}

void print_data(unsigned char *e_ident)
{
	printf(" Data: ");

	if (e_ident[EI_DATA] == ELFDATANONE)
		printf("none\n");
	else if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}

void print_version(unsigned char *e_ident)
{
	printf(" Version: %d", e_ident[EI_VERSION]);

	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	if (e_ident[EI_OSABI] == ELFOSABI_NONE)
		printf("UNIX - System V\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_IRIX)
		printf("UNIX - IRIX\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
		printf("UNIX - FreeBSD\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_TRU64)
		printf("UNIX - TRU64\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_ARM)
		printf("ARM\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
		printf("Standalone App\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}

void print_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type: ");

	if (e_type == ET_NONE)
		printf("NONE (None)\n");
	else if (e_type == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (e_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (e_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (e_type == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", e_type);
}

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	/*Your implementation here*/
}

int main(int argc, char *argv[])
{
	int elf;
	unsigned char e_ident[EI_NIDENT];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(97);
	}

	elf = open(argv[1], O_RDONLY);

	if (elf == -1)
	{
		fprintf(stderr, "Error: Cannot read file %s\n", argv[1]);
		exit(98);
	}

	read(elf, e_ident, EI_NIDENT);

	print_magic(e_ident);
	print_class(e_ident);
	print_data(e_ident);
	print_version(e_ident);
	print_abi(e_ident);
	print_osabi(e_ident);

	close_elf(elf);

	return (0);
}

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		fprintf(stderr, "Error: Cannot close file descriptor %d\n", elf);
		exit(100);
	}
}
