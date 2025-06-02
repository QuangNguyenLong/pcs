#ifndef PCS_WASM_H
#define PCS_WASM_H

#include <pcstream/pcstream.h>
#include <stdint.h>

// Declare all wasm_* function prototypes

uint32_t wasm_pcs_harmonic_bw_estimate(pcs_bw_t *bw_arr,
                                       uint32_t  arr_len,
                                       pcs_bw_t *bw_es);

uint32_t
         wasm_pcs_velocity_viewport_estimate(uint32_t delta_t,
                                             float    p_curr_x,
                                             float    p_curr_y,
                                             float    p_curr_z,
                                             float    p_old_x,
                                             float    p_old_y,
                                             float    p_old_z,
                                             float    v_curr_x,
                                             float    v_curr_y,
                                             float    v_curr_z,
                                             float    v_old_x,
                                             float    v_old_y,
                                             float    v_old_z,
                                             uint32_t estimate_duration,
                                             float   *esMVP);

uint32_t wasm_pcs_hull_visibility_compute(float      *esMVP,
                                          const char *hull_data,
                                          uint32_t    hull_size,
                                          float      *screen_area);

uint32_t wasm_pcs_dp_based_lod_select(uint32_t seq_count,
                                      uint8_t  rep_count,
                                      void    *metadata_buff,
                                      uint32_t metadata_size,
                                      void    *attrib,
                                      pcs_bw_t bandwidth,
                                      pcs_lod_version_t *seq_vers);

pcs_point_cloud_t *wasm_pcs_filrg_pcc_buffer_to_gof(const char *data,
                                                    uint32_t    size,
                                                    uint32_t   *num);

pcs_point_cloud_t *wasm_pcs_gof_get_frame(pcs_point_cloud_t *gof,
                                          int                index);

pcs_filrg_pcc_coord_t *
wasm_pcs_filrg_pcc_frame_get_positions(pcs_point_cloud_t *frame);

uint8_t *wasm_pcs_frame_get_colors(pcs_point_cloud_t *frame);

uint32_t wasm_pcs_frame_get_size(pcs_point_cloud_t *frame);

void     wasm_free(void *ptr);

void    *wasm_malloc(uint32_t size);

#endif
