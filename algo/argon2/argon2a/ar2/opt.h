/*
 * Argon2 source code package
 *
 * Written by Daniel Dinu and Dmitry Khovratovich, 2015
 *
 * This work is licensed under a Creative Commons CC0 1.0 License/Waiver.
 *
 * You should have received a copy of the CC0 Public Domain Dedication along
 * with
 * this software. If not, see
 * <http://creativecommons.org/publicdomain/zero/1.0/>.
 */

#ifndef ARGON2_OPT_H
#define ARGON2_OPT_H

/*
 * Function fills a new memory block. Differs from the
 * @param state Pointer to the just produced block. Content will be updated(!)
 * @param ref_block Pointer to the reference block
 * @param next_block Pointer to the block to be constructed
 * @pre all block pointers must be valid
 */
void ar2_fill_block(__m128i *state, __m128i const *ref_block, __m128i *next_block);

/*
 * Generate pseudo-random values to reference blocks in the segment and puts
 * them into the array
 * @param instance Pointer to the current instance
 * @param position Pointer to the current position
 * @param pseudo_rands Pointer to the array of 64-bit values
 * @pre pseudo_rands must point to @a instance->segment_length allocated values
 */
void ar2_generate_addresses(const argon2_instance_t *instance,
                        const argon2_position_t *position,
                        uint64_t *pseudo_rands);

/*
 * Function that fills the segment using previous segments also from other
 * threads.
 * Identical to the reference code except that it calls optimized FillBlock()
 * @param instance Pointer to the current instance
 * @param position Current position
 * @pre all block pointers must be valid
 */
void ar2_fill_segment(const argon2_instance_t *instance,
                  argon2_position_t position);

#endif /* ARGON2_OPT_H */
