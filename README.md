# ATA Antenna Weights Binary File

A rather rushed solution for the binary storage of complex Antenna-Weights for use at the ATA.

The binary file content is as follows:

Byte Offset | Vector Length | Element C Data Type	| Description
-|-|-|-
0		|	1 | `uint32_t`	| Number of antenna (NANT)
4		|	1 | `uint32_t`	| Number of antenna-channel (NCHAN)
8		|	1 | `uint32_t`	| Number of antenna-polarizations (NPOL)
12	|	NANT | `char[ANTENNA_NAME_LENGTH+1]`	| Antenna names
12+NANT*(ANTENNA_NAME_LENGTH+1) | NANT\*NCHAN\*NPOL | `double _Complex` | Complex Antenna-Weights [NANT=slowest, NCHAN, NPOL=fastest]

*`ANTENNA_NAME_LENGTH` is a compile-time constant defined in the antenna_weights.h file.*

## Reading Antenna Weights

The library-provided `read_antenna_weights` function gathers Antenna-Weights for a given list of antenna-names, for a range of channels.
