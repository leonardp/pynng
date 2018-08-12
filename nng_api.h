// THIS FILE WAS AUTOMATICALLY GENERATED BY ./get_api.sh
typedef struct nng_ctx_s {
 uint32_t id;
} nng_ctx;
typedef struct nng_dialer_s {
 uint32_t id;
} nng_dialer;
typedef struct nng_listener_s {
 uint32_t id;
} nng_listener;
typedef struct nng_pipe_s {
 uint32_t id;
} nng_pipe;
typedef struct nng_socket_s {
 uint32_t id;
} nng_socket;
typedef int32_t nng_duration;
typedef struct nng_msg nng_msg;
typedef struct nng_snapshot nng_snapshot;
typedef struct nng_stat nng_stat;
typedef struct nng_aio nng_aio;
struct nng_sockaddr_inproc {
 uint16_t sa_family;
 char sa_name[(128)];
};
typedef struct nng_sockaddr_inproc nng_sockaddr_inproc;
struct nng_sockaddr_path {
 uint16_t sa_family;
 char sa_path[(128)];
};
typedef struct nng_sockaddr_path nng_sockaddr_path;
typedef struct nng_sockaddr_path nng_sockaddr_ipc;
struct nng_sockaddr_in6 {
 uint16_t sa_family;
 uint16_t sa_port;
 uint8_t sa_addr[16];
};
typedef struct nng_sockaddr_in6 nng_sockaddr_in6;
typedef struct nng_sockaddr_in6 nng_sockaddr_udp6;
typedef struct nng_sockaddr_in6 nng_sockaddr_tcp6;
struct nng_sockaddr_in {
 uint16_t sa_family;
 uint16_t sa_port;
 uint32_t sa_addr;
};
struct nng_sockaddr_zt {
 uint16_t sa_family;
 uint64_t sa_nwid;
 uint64_t sa_nodeid;
 uint32_t sa_port;
};
typedef struct nng_sockaddr_in nng_sockaddr_in;
typedef struct nng_sockaddr_in nng_sockaddr_udp;
typedef struct nng_sockaddr_in nng_sockaddr_tcp;
typedef struct nng_sockaddr_zt nng_sockaddr_zt;
typedef union nng_sockaddr {
 uint16_t s_family;
 nng_sockaddr_ipc s_ipc;
 nng_sockaddr_inproc s_inproc;
 nng_sockaddr_in6 s_in6;
 nng_sockaddr_in s_in;
 nng_sockaddr_zt s_zt;
} nng_sockaddr;
enum nng_sockaddr_family {
 NNG_AF_UNSPEC = 0,
 NNG_AF_INPROC = 1,
 NNG_AF_IPC = 2,
 NNG_AF_INET = 3,
 NNG_AF_INET6 = 4,
 NNG_AF_ZT = 5
};
typedef struct nng_iov {
 void * iov_buf;
 size_t iov_len;
} nng_iov;
extern void nng_fini(void);
extern int nng_close(nng_socket);
extern int nng_socket_id(nng_socket);
extern void nng_closeall(void);
extern int nng_setopt(nng_socket, const char *, const void *, size_t);
extern int nng_setopt_bool(nng_socket, const char *, bool);
extern int nng_setopt_int(nng_socket, const char *, int);
extern int nng_setopt_ms(nng_socket, const char *, nng_duration);
extern int nng_setopt_size(nng_socket, const char *, size_t);
extern int nng_setopt_uint64(nng_socket, const char *, uint64_t);
extern int nng_setopt_string(nng_socket, const char *, const char *);
extern int nng_setopt_ptr(nng_socket, const char *, void *);
extern int nng_getopt(nng_socket, const char *, void *, size_t *);
extern int nng_getopt_bool(nng_socket, const char *, bool *);
extern int nng_getopt_int(nng_socket, const char *, int *);
extern int nng_getopt_ms(nng_socket, const char *, nng_duration *);
extern int nng_getopt_size(nng_socket, const char *, size_t *);
extern int nng_getopt_uint64(nng_socket, const char *, uint64_t *);
extern int nng_getopt_ptr(nng_socket, const char *, void **);
typedef enum {
 NNG_PIPE_EV_ADD_PRE,
 NNG_PIPE_EV_ADD_POST,
 NNG_PIPE_EV_REM_POST,
 NNG_PIPE_EV_NUM,
} nng_pipe_ev;
typedef void (*nng_pipe_cb)(nng_pipe, int, void *);
extern int nng_pipe_notify(nng_socket, int, nng_pipe_cb, void *);
extern int nng_getopt_string(nng_socket, const char *, char **);
extern int nng_listen(nng_socket, const char *, nng_listener *, int);
extern int nng_dial(nng_socket, const char *, nng_dialer *, int);
extern int nng_dialer_create(nng_dialer *, nng_socket, const char *);
extern int nng_listener_create(nng_listener *, nng_socket, const char *);
extern int nng_dialer_start(nng_dialer, int);
extern int nng_listener_start(nng_listener, int);
extern int nng_dialer_close(nng_dialer);
extern int nng_listener_close(nng_listener);
extern int nng_dialer_id(nng_dialer);
extern int nng_listener_id(nng_listener);
extern int nng_dialer_setopt(nng_dialer, const char *, const void *, size_t);
extern int nng_dialer_setopt_bool(nng_dialer, const char *, bool);
extern int nng_dialer_setopt_int(nng_dialer, const char *, int);
extern int nng_dialer_setopt_ms(nng_dialer, const char *, nng_duration);
extern int nng_dialer_setopt_size(nng_dialer, const char *, size_t);
extern int nng_dialer_setopt_uint64(nng_dialer, const char *, uint64_t);
extern int nng_dialer_setopt_ptr(nng_dialer, const char *, void *);
extern int nng_dialer_setopt_string(nng_dialer, const char *, const char *);
extern int nng_dialer_getopt(nng_dialer, const char *, void *, size_t *);
extern int nng_dialer_getopt_bool(nng_dialer, const char *, bool *);
extern int nng_dialer_getopt_int(nng_dialer, const char *, int *);
extern int nng_dialer_getopt_ms(nng_dialer, const char *, nng_duration *);
extern int nng_dialer_getopt_size(nng_dialer, const char *, size_t *);
extern int nng_dialer_getopt_sockaddr(
    nng_dialer, const char *, nng_sockaddr *);
extern int nng_dialer_getopt_uint64(nng_dialer, const char *, uint64_t *);
extern int nng_dialer_getopt_ptr(nng_dialer, const char *, void **);
extern int nng_dialer_getopt_string(nng_dialer, const char *, char **);
extern int nng_listener_setopt(
    nng_listener, const char *, const void *, size_t);
extern int nng_listener_setopt_bool(nng_listener, const char *, bool);
extern int nng_listener_setopt_int(nng_listener, const char *, int);
extern int nng_listener_setopt_ms(nng_listener, const char *, nng_duration);
extern int nng_listener_setopt_size(nng_listener, const char *, size_t);
extern int nng_listener_setopt_uint64(nng_listener, const char *, uint64_t);
extern int nng_listener_setopt_ptr(nng_listener, const char *, void *);
extern int nng_listener_setopt_string(
    nng_listener, const char *, const char *);
extern int nng_listener_getopt(nng_listener, const char *, void *, size_t *);
extern int nng_listener_getopt_bool(nng_listener, const char *, bool *);
extern int nng_listener_getopt_int(nng_listener, const char *, int *);
extern int nng_listener_getopt_ms(
    nng_listener, const char *, nng_duration *);
extern int nng_listener_getopt_size(nng_listener, const char *, size_t *);
extern int nng_listener_getopt_sockaddr(
    nng_listener, const char *, nng_sockaddr *);
extern int nng_listener_getopt_uint64(
    nng_listener, const char *, uint64_t *);
extern int nng_listener_getopt_ptr(nng_listener, const char *, void **);
extern int nng_listener_getopt_string(nng_listener, const char *, char **);
extern const char *nng_strerror(int);
extern int nng_send(nng_socket, void *, size_t, int);
extern int nng_recv(nng_socket, void *, size_t *, int);
extern int nng_sendmsg(nng_socket, nng_msg *, int);
extern int nng_recvmsg(nng_socket, nng_msg **, int);
extern void nng_send_aio(nng_socket, nng_aio *);
extern void nng_recv_aio(nng_socket, nng_aio *);
extern int nng_ctx_open(nng_ctx *, nng_socket);
extern int nng_ctx_close(nng_ctx);
extern int nng_ctx_id(nng_ctx);
extern void nng_ctx_recv(nng_ctx, nng_aio *);
extern void nng_ctx_send(nng_ctx, nng_aio *);
extern int nng_ctx_getopt(nng_ctx, const char *, void *, size_t *);
extern int nng_ctx_getopt_bool(nng_ctx, const char *, bool *);
extern int nng_ctx_getopt_int(nng_ctx, const char *, int *);
extern int nng_ctx_getopt_ms(nng_ctx, const char *, nng_duration *);
extern int nng_ctx_getopt_size(nng_ctx, const char *, size_t *);
extern int nng_ctx_setopt(nng_ctx, const char *, const void *, size_t);
extern int nng_ctx_setopt_bool(nng_ctx, const char *, bool);
extern int nng_ctx_setopt_int(nng_ctx, const char *, int);
extern int nng_ctx_setopt_ms(nng_ctx, const char *, nng_duration);
extern int nng_ctx_setopt_size(nng_ctx, const char *, size_t);
extern void *nng_alloc(size_t);
extern void nng_free(void *, size_t);
extern char *nng_strdup(const char *);
extern void nng_strfree(char *);
extern int nng_aio_alloc(nng_aio **, void (*)(void *), void *);
extern void nng_aio_free(nng_aio *);
extern void nng_aio_stop(nng_aio *);
extern int nng_aio_result(nng_aio *);
extern size_t nng_aio_count(nng_aio *);
extern void nng_aio_cancel(nng_aio *);
extern void nng_aio_abort(nng_aio *, int);
extern void nng_aio_wait(nng_aio *);
extern void nng_aio_set_msg(nng_aio *, nng_msg *);
extern nng_msg *nng_aio_get_msg(nng_aio *);
extern int nng_aio_set_input(nng_aio *, unsigned, void *);
extern void *nng_aio_get_input(nng_aio *, unsigned);
extern int nng_aio_set_output(nng_aio *, unsigned, void *);
extern void *nng_aio_get_output(nng_aio *, unsigned);
extern void nng_aio_set_timeout(nng_aio *, nng_duration);
extern int nng_aio_set_iov(nng_aio *, unsigned, const nng_iov *);
extern void nng_aio_finish(nng_aio *, int);
extern void nng_sleep_aio(nng_duration, nng_aio *);
extern int nng_msg_alloc(nng_msg **, size_t);
extern void nng_msg_free(nng_msg *);
extern int nng_msg_realloc(nng_msg *, size_t);
extern void *nng_msg_header(nng_msg *);
extern size_t nng_msg_header_len(const nng_msg *);
extern void * nng_msg_body(nng_msg *);
extern size_t nng_msg_len(const nng_msg *);
extern int nng_msg_append(nng_msg *, const void *, size_t);
extern int nng_msg_insert(nng_msg *, const void *, size_t);
extern int nng_msg_trim(nng_msg *, size_t);
extern int nng_msg_chop(nng_msg *, size_t);
extern int nng_msg_header_append(nng_msg *, const void *, size_t);
extern int nng_msg_header_insert(nng_msg *, const void *, size_t);
extern int nng_msg_header_trim(nng_msg *, size_t);
extern int nng_msg_header_chop(nng_msg *, size_t);
extern int nng_msg_header_append_u32(nng_msg *, uint32_t);
extern int nng_msg_header_insert_u32(nng_msg *, uint32_t);
extern int nng_msg_header_chop_u32(nng_msg *, uint32_t *);
extern int nng_msg_header_trim_u32(nng_msg *, uint32_t *);
extern int nng_msg_append_u32(nng_msg *, uint32_t);
extern int nng_msg_insert_u32(nng_msg *, uint32_t);
extern int nng_msg_chop_u32(nng_msg *, uint32_t *);
extern int nng_msg_trim_u32(nng_msg *, uint32_t *);
extern int nng_msg_dup(nng_msg **, const nng_msg *);
extern void nng_msg_clear(nng_msg *);
extern void nng_msg_header_clear(nng_msg *);
extern void nng_msg_set_pipe(nng_msg *, nng_pipe);
extern nng_pipe nng_msg_get_pipe(const nng_msg *);
extern int nng_msg_getopt(nng_msg *, int, void *, size_t *);
extern int nng_pipe_getopt(nng_pipe, const char *, void *, size_t *);
extern int nng_pipe_getopt_bool(nng_pipe, const char *, bool *);
extern int nng_pipe_getopt_int(nng_pipe, const char *, int *);
extern int nng_pipe_getopt_ms(nng_pipe, const char *, nng_duration *);
extern int nng_pipe_getopt_size(nng_pipe, const char *, size_t *);
extern int nng_pipe_getopt_sockaddr(nng_pipe, const char *, nng_sockaddr *);
extern int nng_pipe_getopt_uint64(nng_pipe, const char *, uint64_t *);
extern int nng_pipe_getopt_ptr(nng_pipe, const char *, void **);
extern int nng_pipe_getopt_string(nng_pipe, const char *, char **);
extern int nng_pipe_close(nng_pipe);
extern int nng_pipe_id(nng_pipe);
extern nng_socket nng_pipe_socket(nng_pipe);
extern nng_dialer nng_pipe_dialer(nng_pipe);
extern nng_listener nng_pipe_listener(nng_pipe);
enum nng_flag_enum {
 NNG_FLAG_ALLOC = 1,
 NNG_FLAG_NONBLOCK = 2
};
enum nng_stat_type_enum {
 NNG_STAT_LEVEL = 0,
 NNG_STAT_COUNTER = 1
};
enum nng_unit_enum {
 NNG_UNIT_NONE = 0,
 NNG_UNIT_BYTES = 1,
 NNG_UNIT_MESSAGES = 2,
 NNG_UNIT_BOOLEAN = 3,
 NNG_UNIT_MILLIS = 4,
 NNG_UNIT_EVENTS = 5
};
extern int nng_device(nng_socket, nng_socket);
enum nng_errno_enum {
 NNG_EINTR = 1,
 NNG_ENOMEM = 2,
 NNG_EINVAL = 3,
 NNG_EBUSY = 4,
 NNG_ETIMEDOUT = 5,
 NNG_ECONNREFUSED = 6,
 NNG_ECLOSED = 7,
 NNG_EAGAIN = 8,
 NNG_ENOTSUP = 9,
 NNG_EADDRINUSE = 10,
 NNG_ESTATE = 11,
 NNG_ENOENT = 12,
 NNG_EPROTO = 13,
 NNG_EUNREACHABLE = 14,
 NNG_EADDRINVAL = 15,
 NNG_EPERM = 16,
 NNG_EMSGSIZE = 17,
 NNG_ECONNABORTED = 18,
 NNG_ECONNRESET = 19,
 NNG_ECANCELED = 20,
 NNG_ENOFILES = 21,
 NNG_ENOSPC = 22,
 NNG_EEXIST = 23,
 NNG_EREADONLY = 24,
 NNG_EWRITEONLY = 25,
 NNG_ECRYPTO = 26,
 NNG_EPEERAUTH = 27,
 NNG_ENOARG = 28,
 NNG_EAMBIGUOUS = 29,
 NNG_EBADTYPE = 30,
 NNG_EINTERNAL = 1000,
 NNG_ESYSERR = 0x10000000,
 NNG_ETRANERR = 0x20000000
};
typedef struct nng_url {
 char *u_rawurl;
 char *u_scheme;
 char *u_userinfo;
 char *u_host;
 char *u_hostname;
 char *u_port;
 char *u_path;
 char *u_query;
 char *u_fragment;
 char *u_requri;
} nng_url;
extern int nng_url_parse(nng_url **, const char *);
extern void nng_url_free(nng_url *);
extern int nng_url_clone(nng_url **, const nng_url *);
extern const char *nng_version(void);
