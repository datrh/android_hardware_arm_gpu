#ifndef __MALI_CLOCK_H__
#define __MALI_CLOCK_H__
#include <linux/version.h>
#include <linux/pm.h>
#include <linux/io.h>
#include <linux/types.h>
#include <linux/of.h>

#include <asm/io.h>
#include <linux/clk.h>
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3, 14, 29))
#include <linux/amlogic/iomap.h>
#endif

//extern int mali_clock_init(struct platform_device *dev);
int mali_clock_init_clk_tree(struct platform_device *pdev);

typedef int (*critical_t)(size_t param);
int mali_clock_critical(critical_t critical, size_t param);

int mali_clock_init(mali_plat_info_t*);
int mali_clock_set(unsigned int index);
void disable_clock(void);
void enable_clock(void);
u32 get_mali_freq(u32 idx);
void set_str_src(u32 data);
int mali_dt_info(struct platform_device *pdev,
        struct mali_plat_info_t *mpdata);
#endif
