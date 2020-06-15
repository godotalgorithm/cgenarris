#ifndef SPG_GENERATOR_H
#define SPG_GENERATOR_H

#define POS_MAX 47
#define MAX_ORDER 16

#include "crystal.h"

//for storing allowed spacegroup and position
typedef struct
{
	float *usable_mol_axes;
	float *usable_view_dir;
	int num_combinations;
	
}COMPATIBLE_AXES;

/*
 * spg: is the space group.
 * num_allowed_pos: is the number of compatible positions for this spg.
 * allowed_pos: is a list of allowed pos; 0 for general position,
 * the order is defined by the database.
 * pos_overlap_list: is the overlap list for each position. overlap list 
 * is the list of molecules that overlap with the first molecule.
 * compatible_axes: stores information about the combination of 
 * viewing directions and molecular axes.
 */
typedef struct 
{
	unsigned int spg;
	unsigned int num_allowed_pos;
	unsigned int *allowed_pos;
	int *pos_overlap_list[MAX_ORDER];
	COMPATIBLE_AXES compatible_axes[POS_MAX];
	
}COMPATIBLE_SPG;


int generate_crystal(crystal* random_crystal, molecule* mol,float volume,
	float Z, float Zp_max, int spg, COMPATIBLE_SPG compatible_spg[],
	int len_compatible_spg, int compatible_spg_index);


int find_num_structure_for_spg(int num_structures, char spg_dist_type[10], int spg, int Z);


#endif
