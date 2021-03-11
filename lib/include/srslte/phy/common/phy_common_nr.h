/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2013-2020 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

#ifndef SRSLTE_PHY_COMMON_NR_H
#define SRSLTE_PHY_COMMON_NR_H

#include "phy_common.h"
#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defines the number of symbols per slot. Defined by TS 38.211 v15.8.0 Table 4.3.2-1.
 */
#define SRSLTE_NSYMB_PER_SLOT_NR 14U

/**
 * @brief Defines the resource grid size in physical resource elements (frequency and time domain)
 */
#define SRSLTE_SLOT_LEN_RE_NR(nof_prb) (nof_prb * SRSLTE_NRE * SRSLTE_NSYMB_PER_SLOT_NR)

#define SRSLTE_SLOT_MAX_LEN_RE_NR (SRSLTE_SLOT_LEN_RE_NR(SRSLTE_MAX_PRB_NR))
#define SRSLTE_SLOT_MAX_NOF_BITS_NR (SRSLTE_SLOT_MAX_LEN_RE_NR * SRSLTE_MAX_QM)
#define SRSLTE_MAX_LAYERS_NR 8

/**
 * @brief Defines the maximum numerology supported. Defined by TS 38.211 v15.8.0 Table 4.3.2-1.
 */
#define SRSLTE_NR_MAX_NUMEROLOGY 4U

/**
 * @brief Defines the symbol duration, including cyclic prefix
 */
#define SRSLTE_SUBC_SPACING_NR(NUM) (15000U << (NUM))

/**
 * @brief Defines the number of slots per SF. Defined by TS 38.211 v15.8.0 Table 4.3.2-1.
 */
#define SRSLTE_NSLOTS_PER_SF_NR(NUM) (1U << (NUM))

/**
 * @brief Defines the number of slots per frame. Defined by TS 38.211 v15.8.0 Table 4.3.2-1.
 */
#define SRSLTE_NSLOTS_PER_FRAME_NR(NUM) (SRSLTE_NSLOTS_PER_SF_NR(NUM) * SRSLTE_NOF_SF_X_FRAME)

/**
 * @brief Bounds slot index into the frame
 */
#define SRSLTE_SLOT_NR_MOD(NUM, N) ((N) % SRSLTE_NSLOTS_PER_FRAME_NR(NUM))

/**
 * @brief Maximum Carrier identification value. Defined by TS 38.331 v15.10.0 as PhysCellId from 0 to 1007.
 */
#define SRSLTE_MAX_ID_NR 1007

/**
 * @brief Maximum number of physical resource blocks (PRB) that a 5G NR can have. This is defined by TS 38.331 v15.10.0
 * as maxNrofPhysicalResourceBlocks
 */
#define SRSLTE_MAX_PRB_NR 275

/**
 * @brief Maximum start sub-carrier index for the carrier relative point
 */
#define SRSLTE_MAX_START_NR 2199

/**
 * @brief defines the maximum number of Aggregation levels: 1, 2, 4, 8 and 16
 */
#define SRSLTE_SEARCH_SPACE_NOF_AGGREGATION_LEVELS_NR 5

/**
 * @brief defines the maximum number of RE
 */
#define SRSLTE_PDCCH_MAX_RE ((SRSLTE_NRE - 3U) * (1U << (SRSLTE_SEARCH_SPACE_NOF_AGGREGATION_LEVELS_NR - 1U)) * 6U)

/**
 * @brief defines the maximum number of candidates for a given Aggregation level
 */
#define SRSLTE_SEARCH_SPACE_MAX_NOF_CANDIDATES_NR 8

/**
 * @brief defines the maximum number of monitored PDCCH candidates per slot and per serving cell according to TS 38.213
 * Table 10.1-2
 */
#define SRSLTE_MAX_NOF_CANDIDATES_NR 44

/**
 * @brief defines the maximum number of resource elements per PRB
 * @remark Defined in TS 38.214 V15.10.0 5.1.3.2 Transport block size determination, point 1, second bullet
 */
#define SRSLTE_MAX_NRE_NR 156

/**
 * @brief defines the maximum number of resource elements in a PDSCH transmission
 * @remark deduced from in TS 36.214 V15.10.0 5.1.3.2 Transport block size determination
 */
#define SRSLTE_PDSCH_MAX_RE_NR (SRSLTE_MAX_NRE_NR * SRSLTE_MAX_PRB_NR)

/**
 * @brief Maximum number of PDSCH time domain resource allocations. This is defined by TS 38.331 v15.10.0
 * as maxNrofDL-Allocations
 */
#define SRSLTE_MAX_NOF_DL_ALLOCATION 16

/**
 * @brief Maximum dl-DataToUL-ACK value. This is defined by TS 38.331 v15.10.1 in PUCCH-Config
 */
#define SRSLTE_MAX_NOF_DL_DATA_TO_UL 8

typedef enum SRSLTE_API {
  srslte_coreset_mapping_type_non_interleaved = 0,
  srslte_coreset_mapping_type_interleaved,
} srslte_coreset_mapping_type_t;

typedef enum SRSLTE_API {
  srslte_coreset_bundle_size_n2 = 0,
  srslte_coreset_bundle_size_n3,
  srslte_coreset_bundle_size_n6,
} srslte_coreset_bundle_size_t;

typedef enum SRSLTE_API {
  srslte_coreset_precoder_granularity_contiguous = 0,
  srslte_coreset_precoder_granularity_reg_bundle
} srslte_coreset_precoder_granularity_t;

/**
 * @brief PDSCH mapping type
 * @remark Described in TS 38.331 V15.10.0 Section PDSCH-TimeDomainResourceAllocationList
 */
typedef enum SRSLTE_API { srslte_sch_mapping_type_A = 0, srslte_sch_mapping_type_B } srslte_sch_mapping_type_t;

/**
 * @brief Search spaces
 * @remark Described in TS 38.213 V15.10.0 Section 10.1 UE procedure for determining physical downlink control channel
 * assignment
 */
typedef enum SRSLTE_API {
  srslte_search_space_type_common_0 = 0, ///< configured by pdcch-ConfigSIB1 in MIB or by searchSpaceSIB1 in
                                         ///< PDCCH-ConfigCommon or by searchSpaceZero in PDCCH-ConfigCommon
  srslte_search_space_type_common_0A,    ///< configured by searchSpaceOtherSystemInformation in PDCCH-ConfigCommon
  srslte_search_space_type_common_1,     ///< configured by ra-SearchSpace in PDCCH-ConfigCommon
  srslte_search_space_type_common_2,     ///< configured by pagingSearchSpace in PDCCH-ConfigCommon
  srslte_search_space_type_common_3,     ///< configured by SearchSpace in PDCCH-Config with searchSpaceType = common
  srslte_search_space_type_ue,  ///< configured by SearchSpace in PDCCH-Config with searchSpaceType = ue-Specific
  srslte_search_space_type_rar, ///< Indicates that a grant was given by MAC RAR as described in TS 38.213 clause 8.2
  srslte_search_space_type_cg   ///< Indicates that a grant was given by Configured Grant from the upper layers
} srslte_search_space_type_t;

/**
 * @brief Helper macro to get if a search space type is common or not
 */
#define SRSLTE_SEARCH_SPACE_IS_COMMON(SS_TYPE) ((SS_TYPE) < srslte_search_space_type_ue)

/**
 * @brief RAR content length in bits (see TS 38.321 Sec 6.2.3)
 */
#define SRSLTE_RAR_UL_GRANT_NBITS (27)

/**
 * @brief Indicates the MCS table the UE shall use for PDSCH and/or PUSCH without transform precoding
 */
typedef enum SRSLTE_API {
  srslte_mcs_table_64qam = 0,
  srslte_mcs_table_256qam,
  srslte_mcs_table_qam64LowSE,
  srslte_mcs_table_N
} srslte_mcs_table_t;

/**
 * @brief RNTI types
 * @remark Usage described in TS 38.321 Table 7.1-2: RNTI usage.
 */
typedef enum SRSLTE_API {
  srslte_rnti_type_c = 0,
  srslte_rnti_type_p,      ///< @brief Paging and System Information change notification (PCH)
  srslte_rnti_type_si,     ///< @brief Broadcast of System Information (DL-SCH)
  srslte_rnti_type_ra,     ///< @brief Random Access Response (DL-SCH)
  srslte_rnti_type_tc,     ///< @brief Contention Resolution (when no valid C-RNTI is available) (DL-SCH)
  srslte_rnti_type_cs,     ///< @brief Configured scheduled unicast transmission (DL-SCH, UL-SCH)
  srslte_rnti_type_sp_csi, ///< @brief Activation of Semi-persistent CSI reporting on PUSCH
  srslte_rnti_type_mcs_c,  ///< @brief Dynamically scheduled unicast transmission (DL-SCH)
} srslte_rnti_type_t;

/**
 * @brief DCI formats
 * @remark Described in TS 38.212 V15.9.0 Section 7.3.1 DCI formats
 */
typedef enum SRSLTE_API {
  srslte_dci_format_nr_0_0 = 0, ///< @brief Scheduling of PUSCH in one cell
  srslte_dci_format_nr_0_1,     ///< @brief Scheduling of PUSCH in one cell
  srslte_dci_format_nr_1_0,     ///< @brief Scheduling of PDSCH in one cell
  srslte_dci_format_nr_1_1,     ///< @brief Scheduling of PDSCH in one cell
  srslte_dci_format_nr_2_0,     ///< @brief Notifying a group of UEs of the slot format
  srslte_dci_format_nr_2_1, ///< @brief Notifying a group of UEs of the PRB(s) and OFDM symbol(s) where UE may assume no
                            ///< transmission is intended for the UE
  srslte_dci_format_nr_2_2, ///< @brief Transmission of TPC commands for PUCCH and PUSCH
  srslte_dci_format_nr_2_3, ///< @brief Transmission of a group of TPC commands for SRS transmissions by one or more UEs
  srslte_dci_format_nr_rar, ///< @brief Scheduling a transmission of PUSCH from RAR
  srslte_dci_format_nr_cg   ///< @brief Scheduling of PUSCH using a configured grant
} srslte_dci_format_nr_t;

/**
 * @brief Overhead configuration provided by higher layers
 * @remark Described in TS 38.331 V15.10.0 PDSCH-ServingCellConfig
 * @remark Described in TS 38.331 V15.10.0 PUSCH-ServingCellConfig
 */
typedef enum SRSLTE_API {
  srslte_xoverhead_0 = 0,
  srslte_xoverhead_6,
  srslte_xoverhead_12,
  srslte_xoverhead_18
} srslte_xoverhead_t;

/**
 * @brief PDSCH HARQ ACK codebook configuration
 * @remark Described in TS 38.331 V15.10.0 PhysicalCellGroupConfig
 */
typedef enum SRSLTE_API {
  srslte_pdsch_harq_ack_codebook_none = 0,
  srslte_pdsch_harq_ack_codebook_semi_static,
  srslte_pdsch_harq_ack_codebook_dynamic,
} srslte_pdsch_harq_ack_codebook_t;
/**
 * @brief NR carrier parameters. It is a combination of fixed cell and bandwidth-part (BWP)
 */
typedef struct SRSLTE_API {
  uint32_t id;
  uint32_t numerology;
  uint32_t nof_prb;
  uint32_t start;
  uint32_t max_mimo_layers; ///< @brief DL: Indicates the maximum number of MIMO layers to be used for PDSCH in all BWPs
                            ///< of this serving cell. (see TS 38.212 [17], clause 5.4.2.1). UL: Indicates the maximum
                            ///< MIMO layer to be used for PUSCH in all BWPs of the normal UL of this serving cell (see
                            ///< TS 38.212 [17], clause 5.4.2.1)
} srslte_carrier_nr_t;

/**
 * @brief NR Slot parameters. It contains parameters that change in a slot basis.
 */
typedef struct SRSLTE_API {
  /// Slot index in the radio frame
  uint32_t idx;

  /// Left for future parameters
  /// ...
} srslte_slot_cfg_t;

/**
 * @brief Min number of OFDM symbols in a control resource set.
 */
#define SRSLTE_CORESET_DURATION_MIN 1

/**
 * @brief Max number of OFDM symbols in a control resource set. Specified in TS 38.331 V15.10.0 as maxCoReSetDuration
 */
#define SRSLTE_CORESET_DURATION_MAX 3

/**
 * @brief Number of possible CORESET frequency resources.
 */
#define SRSLTE_CORESET_FREQ_DOMAIN_RES_SIZE 45

/**
 * @brief Max value for shift index
 */
#define SRSLTE_CORESET_SHIFT_INDEX_MAX (SRSLTE_CORESET_NOF_PRB_MAX - 1)

/**
 * @brief CORESET parameters as defined in TS 38.331 V15.10.0 - ControlResourceSet
 */
typedef struct SRSLTE_API {
  uint32_t                      id;
  uint32_t                      coreset_id;
  srslte_coreset_mapping_type_t mapping_type;
  uint32_t                      duration;
  bool                          freq_resources[SRSLTE_CORESET_FREQ_DOMAIN_RES_SIZE];
  srslte_coreset_bundle_size_t  interleaver_size;

  bool                                  dmrs_scrambling_id_present;
  uint32_t                              dmrs_scrambling_id;
  srslte_coreset_precoder_granularity_t precoder_granularity;
  srslte_coreset_bundle_size_t          reg_bundle_size;
  uint32_t                              shift_index;
  /** Missing TCI parameters */
} srslte_coreset_t;

/**
 * @brief SearchSpace parameters as defined in TS 38.331 v15.10.0 SearchSpace sequence
 */
typedef struct SRSLTE_API {
  uint32_t                   id;
  uint32_t                   coreset_id;
  uint32_t                   duration; // in slots
  srslte_search_space_type_t type;
  uint32_t                   nof_candidates[SRSLTE_SEARCH_SPACE_NOF_AGGREGATION_LEVELS_NR];
} srslte_search_space_t;

/**
 * @brief TDD pattern configuration
 */
typedef struct SRSLTE_API {
  uint32_t period_ms;      ///< Period in milliseconds, set to 0 if not present
  uint32_t nof_dl_slots;   ///< Number of consecutive full DL slots at the beginning of each DL-UL pattern
  uint32_t nof_dl_symbols; ///< Number of consecutive DL symbols in the beginning of the slot following the last DL slot
  uint32_t nof_ul_slots;   ///< Number of consecutive full UL slots at the end of each DL-UL pattern
  uint32_t nof_ul_symbols; ///< Number of consecutive UL symbols in the end of the slot preceding the first full UL slot
} srslte_tdd_pattern_t;

/**
 * @brief TDD configuration as described in TS 38.331 v15.10.0 TDD-UL-DL-ConfigCommon
 */
typedef struct SRSLTE_API {
  srslte_tdd_pattern_t pattern1;
  srslte_tdd_pattern_t pattern2;
} srslte_tdd_config_nr_t;

/**
 * @brief Get the RNTI type name for NR
 * @param rnti_type RNTI type name
 * @return Constant string with the RNTI type name
 */
SRSLTE_API const char* srslte_rnti_type_str(srslte_rnti_type_t rnti_type);

/**
 * @brief Calculates the bandwidth of a given CORESET in physical resource blocks (PRB) . This function uses the
 * frequency domain resources bit-map for counting the number of PRB.
 *
 * @attention Prior to this function call, the frequency domain resources bit-map shall be zeroed beyond the
 * carrier.nof_prb / 6 index, otherwise the CORESET bandwidth might be greater than the carrier.
 *
 * @param coreset provides the given CORESET configuration
 * @return The number of PRB that the CORESET takes in frequency domain
 */
SRSLTE_API uint32_t srslte_coreset_get_bw(const srslte_coreset_t* coreset);

/**
 * @brief Calculates the number of Physical Resource Elements (time and frequency domain) that a given CORESET uses.
 * This function uses the frequency domain resources bit-map and duration to compute the number of symbols.
 *
 * @attention Prior to this function call, the frequency domain resources bit-map shall be zeroed beyond the
 * carrier.nof_prb / 6 index, otherwise the CORESET bandwidth might be greater than the carrier.
 *
 * @param coreset provides the given CORESET configuration
 * @return The number of resource elements that compose the coreset
 */
SRSLTE_API uint32_t srslte_coreset_get_sz(const srslte_coreset_t* coreset);

/**
 * @brief Get the NR PDSCH mapping type in string
 * @param mapping_type Mapping type
 * @return Constant string with PDSCH mapping type
 */
SRSLTE_API const char* srslte_sch_mapping_type_to_str(srslte_sch_mapping_type_t mapping_type);

/**
 * @brief Get the MCS table string
 * @param mcs_table MCS table value
 * @return Constant string with the MCS table name
 */
SRSLTE_API const char* srslte_mcs_table_to_str(srslte_mcs_table_t mcs_table);

/**
 * @brief Get the MCS table value from a string
 * @param str Points to a given string
 * @return The MCS table value
 */
SRSLTE_API srslte_mcs_table_t srslte_mcs_table_from_str(const char* str);

/**
 * @brief Computes the minimum valid symbol size for a given amount of PRB
 * @attention The valid FFT sizes are radix 2 and radix 3 between 128 to 4096 points.
 * @param nof_prb Number of PRB
 * @return The minimum valid FFT size if the number of PRB is in range, 0 otherwise
 */
SRSLTE_API uint32_t srslte_min_symbol_sz_rb(uint32_t nof_prb);

/**
 * @brief Computes the time in seconds between two symbols in a slot
 * @note l0 is expected to be smaller than l1
 * @remark All symbol size reference and values are taken from TS 38.211 section 5.3 OFDM baseband signal generation
 * @param l0 First symbol index within the slot
 * @param l1 Second symbol index within the slot
 * @param numerology NR Carrier numerology
 * @return Returns the time in seconds between the two symbols if the condition above is satisfied, 0 seconds otherwise
 */
SRSLTE_API float srslte_symbol_distance_s(uint32_t l0, uint32_t l1, uint32_t numerology);

/**
 * @brief Decides whether a given slot is configured as Downlink
 * @param cfg Provides TDD configuration
 * @param numerology Provides BWP numerology
 * @param slot_idx Slot index in the frame for the given numerology
 * @return true if the provided slot index is configured for Downlink
 */
SRSLTE_API bool srslte_tdd_nr_is_dl(const srslte_tdd_config_nr_t* cfg, uint32_t numerology, uint32_t slot_idx);

/**
 * @brief Decides whether a given slot is configured as Uplink
 * @param cfg Provides TDD configuration
 * @param numerology Provides BWP numerology
 * @param slot_idx Slot index in the frame for the given numerology
 * @return true if the provided slot index is configured for Uplink
 */
SRSLTE_API bool srslte_tdd_nr_is_ul(const srslte_tdd_config_nr_t* cfg, uint32_t numerology, uint32_t slot_idx);

#ifdef __cplusplus
}
#endif

#endif // SRSLTE_PHY_COMMON_NR_H
