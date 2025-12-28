#ifndef KSU_SUSFS_H
#define KSU_SUSFS_H

#include <linux/version.h>
#include <linux/types.h>
#include <linux/utsname.h>
#include <linux/hashtable.h>
#include <linux/path.h>
#include <linux/susfs_def.h>

#define SUSFS_VERSION "v2.0.0"
#if LINUX_VERSION_CODE < KERNEL_VERSION(5,0,0)
#define SUSFS_VARIANT "NON-GKI"
#else
#define SUSFS_VARIANT "GKI"
#endif

/*********/
/* MACRO */
/*********/
#define getname_safe(name) (name == NULL ? ERR_PTR(-EINVAL) : getname(name))
#define putname_safe(name) (IS_ERR(name) ? NULL : putname(name))

/**********/
/* STRUCT */
/**********/
/* sus_path */
#ifdef CONFIG_KSU_SUSFS_SUS_PATH
struct st_susfs_sus_path {
	unsigned long                           target_ino;
	char                                    target_pathname[SUSFS_MAX_LEN_PATHNAME];
	unsigned int                            i_uid;
	int                                     err;
};

struct st_susfs_sus_path_list {
	struct list_head                 list;
	struct st_susfs_sus_path         info;
	char                             target_pathname[SUSFS_MAX_LEN_PATHNAME];
	size_t                           path_len;
};

struct st_external_dir {
	char                                    target_pathname[SUSFS_MAX_LEN_PATHNAME];
	bool                                    is_inited;
	int                                     cmd;
	int                                     err;
};

struct st_sdcard_path {
	char                                    target_pathname[SUSFS_MAX_LEN_PATHNAME];
	unsigned long                           target_dev;
	int                                     err;
};
#endif

/* sus_mount */
#ifdef CONFIG_KSU_SUSFS_SUS_MOUNT
struct st_susfs_hide_sus_mnts_for_all_procs {
	bool                                    enabled;
	int                                     err;
};
#endif

/* sus_kstat */
#ifdef CONFIG_KSU_SUSFS_SUS_KSTAT
struct st_susfs_sus_kstat {
	int                                     is_statically;
	unsigned long                           target_ino; // the ino after bind mounted or overlayed
	char                                    target_pathname[SUSFS_MAX_LEN_PATHNAME];
	unsigned long                           spoofed_ino;
	unsigned long                           spoofed_dev;
	unsigned int                            spoofed_nlink;
	long long                               spoofed_size;
	long                                    spoofed_atime_tv_sec;
	long                                    spoofed_mtime_tv_sec;
	long                                    spoofed_ctime_tv_sec;
	long                                    spoofed_atime_tv_nsec;
	long                                    spoofed_mtime_tv_nsec;
	long                                    spoofed_ctime_tv_nsec;
	unsigned long                           spoofed_blksize;
	unsigned long long                      spoofed_blocks;
	int                                     err;
};

struct st_susfs_sus_kstat_hlist {
	unsigned long                           target_ino;
	struct st_susfs_sus_kstat               info;
	struct hlist_node                       node;
};
#endif

/* spoof_uname */
#ifdef CONFIG_KSU_SUSFS_SPOOF_UNAME
struct st_susfs_uname {
	char                                    release[__NEW_UTS_LEN+1];
	char                                    version[__NEW_UTS_LEN+1];
	int                                     err;
};
#endif

/* enable_log */
#ifdef CONFIG_KSU_SUSFS_ENABLE_LOG
struct st_susfs_log {
	bool                                    enabled;
	int                                     err;
};
#endif

/* spoof_cmdline_or_bootconfig */
#ifdef CONFIG_KSU_SUSFS_SPOOF_CMDLINE_OR_BOOTCONFIG
struct st_susfs_spoof_cmdline_or_bootconfig {
	char                                    fake_cmdline_or_bootconfig[SUSFS_FAKE_CMDLINE_OR_BOOTCONFIG_SIZE];
	int                                     err;
};
#endif

/* open_redirect */
#ifdef CONFIG_KSU_SUSFS_OPEN_REDIRECT
struct st_susfs_open_redirect {
	unsigned long                           target_ino;
	char                                    target_pathname[SUSFS_MAX_LEN_PATHNAME];
	char                                    redirected_pathname[SUSFS_MAX_LEN_PATHNAME];
	int                                     err;
};

struct st_susfs_open_redirect_hlist {
	unsigned long                           target_ino;
	char                                    target_pathname[SUSFS_MAX_LEN_PATHNAME];
	char                                    redirected_pathname[SUSFS_MAX_LEN_PATHNAME];
	struct hlist_node                       node;
};
#endif

/* sus_map */
#ifdef CONFIG_KSU_SUSFS_SUS_MAP
struct st_susfs_sus_map {
	char                                    target_pathname[SUSFS_MAX_LEN_PATHNAME];
	int                                     err;
};
#endif

/* avc log spoofing */
struct st_susfs_avc_log_spoofing {
	bool                                    enabled;
	int                                     err;
};

/* get enabled features */
struct st_susfs_enabled_features {
	char                                    enabled_features[SUSFS_ENABLED_FEATURES_SIZE];
	int                                     err;
};

/* show variant */
struct st_susfs_variant {
	char                                    susfs_variant[16];
	int                                     err;
};

/* show version */
struct st_susfs_version {
	char                                    susfs_version[16];
	int                                     err;
};

/***********************/
/* FORWARD DECLARATION */
/***********************/
/* sus_path */
#ifdef CONFIG_KSU_SUSFS_SUS_PATH
void susfs_set_i_state_on_external_dir(void __user **user_info);
void susfs_add_sus_path(void __user **user_info);
void susfs_add_sus_path_loop(void __user **user_info);
#endif
/* sus_mount */
#ifdef CONFIG_KSU_SUSFS_SUS_MOUNT
void susfs_set_hide_sus_mnts_for_all_procs(void __user **user_info);
#endif // #ifdef CONFIG_KSU_SUSFS_SUS_MOUNT

/* sus_kstat */
#ifdef CONFIG_KSU_SUSFS_SUS_KSTAT
void susfs_add_sus_kstat(void __user **user_info);
void susfs_update_sus_kstat(void __user **user_info);
void susfs_sus_ino_for_generic_fillattr(unsigned long ino, struct kstat *stat);
void susfs_sus_ino_for_show_map_vma(unsigned long ino, dev_t *out_dev, unsigned long *out_ino);
#endif
/* spoof_uname */
#ifdef CONFIG_KSU_SUSFS_SPOOF_UNAME
void susfs_set_uname(void __user **user_info);
void susfs_spoof_uname(struct new_utsname* tmp);
#endif
/* enable_log */
#ifdef CONFIG_KSU_SUSFS_ENABLE_LOG
void susfs_enable_log(void __user **user_info);
#endif
/* spoof_cmdline_or_bootconfig */
#ifdef CONFIG_KSU_SUSFS_SPOOF_CMDLINE_OR_BOOTCONFIG
void susfs_set_cmdline_or_bootconfig(void __user **user_info);
int susfs_spoof_cmdline_or_bootconfig(struct seq_file *m);
#endif
/* open_redirect */
#ifdef CONFIG_KSU_SUSFS_OPEN_REDIRECT
void susfs_add_open_redirect(void __user **user_info);
struct filename* susfs_get_redirected_path(unsigned long ino);
#endif
/* sus_map */
#ifdef CONFIG_KSU_SUSFS_SUS_MAP
void susfs_add_sus_map(void __user **user_info);
#endif

void susfs_set_avc_log_spoofing(void __user **user_info);

void susfs_get_enabled_features(void __user **user_info);
void susfs_show_variant(void __user **user_info);
void susfs_show_version(void __user **user_info);

/* susfs_init */
void susfs_init(void);

#endif
