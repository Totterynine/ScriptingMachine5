#ifndef SMV_HOST_H
#define SMV_HOST_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

int smv_host_init(const char* runtime_config_path);
void smv_host_shutdown();

smv_assembly_t smv_load_assembly(const char* assembly_path);

void* smv_get_method(const char* namespace_, const char* type, const char* method);

#ifdef __cplusplus
}
#endif

#endif