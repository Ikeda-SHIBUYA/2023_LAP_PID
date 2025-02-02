#include "kernel/kernel_impl.h"
#include "common/module_common.h"
#include "platform_interface_layer.h"

#include "api.cfg.h"
#include "app.h"
ID _module_id_APP_INIT_TASK __attribute__((section (".module.text")));
static STK_T _module_ustack_APP_INIT_TASK[COUNT_STK_T(STACK_SIZE)];

ID _module_id_MAIN_TASK __attribute__((section (".module.text")));
static STK_T _module_ustack_MAIN_TASK[COUNT_STK_T(STACK_SIZE)];

ID _module_id_TRACER_TASK __attribute__((section (".module.text")));
static STK_T _module_ustack_TRACER_TASK[COUNT_STK_T(STACK_SIZE)];

static const T_CTSK _module_ctsk_tab[3] = {
	{ TA_ACT, 0, _app_init_task, TPRI_APP_INIT_TASK, ROUND_STK_T(STACK_SIZE), _module_ustack_APP_INIT_TASK, DEFAULT_SSTKSZ, NULL },
	{ TA_ACT, 0, main_task, MAIN_PRIORITY, ROUND_STK_T(STACK_SIZE), _module_ustack_MAIN_TASK, DEFAULT_SSTKSZ, NULL },
	{ TA_NULL, 0, tracer_task, TRACER_PRIORITY, ROUND_STK_T(STACK_SIZE), _module_ustack_TRACER_TASK, DEFAULT_SSTKSZ, NULL },
};

ID _module_id_CYC_TRACER __attribute__((section (".module.text")));

static const T_DML_CCYC _module_ccyc_tab[1] = {
	{ TA_NULL, 10U * 1000U, 1U * 1000U,  TNFY_ACTTSK,  (intptr_t)&_module_id_TRACER_TASK, 0, 0, 0 },
};

const uint32_t _module_cfg_entry_num = 4;

const MOD_CFG_ENTRY _module_cfg_tab[4] = {
	{ TSFN_CRE_TSK, &_module_ctsk_tab[0], &_module_id_APP_INIT_TASK },
	{ TSFN_CRE_TSK, &_module_ctsk_tab[1], &_module_id_MAIN_TASK },
	{ TSFN_CRE_TSK, &_module_ctsk_tab[2], &_module_id_TRACER_TASK },
	{ TSFN_CRE_CYC, &_module_ccyc_tab[0], &_module_id_CYC_TRACER },
};

const uint32_t _module_pil_version = PIL_VERSION;
