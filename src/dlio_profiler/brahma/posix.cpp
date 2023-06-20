//
// Created by hariharan on 8/16/22.
//
#include <cpp-logger/logger.h>
#include <dlio_profiler/brahma/posix.h>
#include <dlio_profiler/dlio_logger.h>

#define CATEGORY "POSIX"

std::shared_ptr<brahma::POSIXDLIOProfiler> brahma::POSIXDLIOProfiler::instance = nullptr;
int brahma::POSIXDLIOProfiler::open(const char *pathname, int flags, ...) {
  BRAHMA_MAP_OR_FAIL(open);
  DLIO_LOGGER_START(pathname);
  int ret = -1;
  if (flags & O_CREAT) {
    va_list args;
    va_start(args, flags);
    int mode = va_arg(args, int);
    va_end(args);
    ret = __real_open(pathname, flags, mode);
  } else {
    ret = __real_open(pathname, flags);
  }
  DLIO_LOGGER_UPDATE(ret);
  DLIO_LOGGER_END();
  if (trace) this->trace(ret);
  return ret;
}
int brahma::POSIXDLIOProfiler::close(int fd) {
  BRAHMA_MAP_OR_FAIL(close);
  DLIO_LOGGER_START(fd);
  int ret = __real_close(fd);
  DLIO_LOGGER_END();
  if (trace) this->remove_trace(fd);
  return ret;
}
ssize_t brahma::POSIXDLIOProfiler::write(int fd, const void *buf, size_t count) {
  BRAHMA_MAP_OR_FAIL(write);
  DLIO_LOGGER_START(fd);
  ssize_t ret = __real_write(fd, buf, count);
  DLIO_LOGGER_END();
  return ret;
}
ssize_t brahma::POSIXDLIOProfiler::read(int fd, void *buf, size_t count) {
  BRAHMA_MAP_OR_FAIL(read);
  DLIO_LOGGER_START(fd);
  ssize_t ret = __real_read(fd, buf, count);
  DLIO_LOGGER_END();
  return ret;
}
off_t brahma::POSIXDLIOProfiler::lseek(int fd, off_t offset, int whence) {
  BRAHMA_MAP_OR_FAIL(lseek);
  DLIO_LOGGER_START(fd);
  ssize_t ret = __real_lseek(fd, offset, whence);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::creat64(const char *path, mode_t mode) {
  BRAHMA_MAP_OR_FAIL(creat64);
  DLIO_LOGGER_START(path);
  int ret = __real_creat64(path, mode);
  DLIO_LOGGER_END();
  if (trace) this->trace(path);
  return ret;
}

int brahma::POSIXDLIOProfiler::open64(const char *path, int flags, ...) {
  BRAHMA_MAP_OR_FAIL(open64);
  DLIO_LOGGER_START(path);
  int ret = -1;
  if (flags & O_CREAT) {
    va_list args;
    va_start(args, flags);
    int mode = va_arg(args, int);
    va_end(args);
    ret = __real_open64(path, flags, mode);
  }else {
    ret = __real_open64(path, flags);
  }
  DLIO_LOGGER_END();
  if (trace) this->trace(path);
  return ret;
}

off64_t brahma::POSIXDLIOProfiler::lseek64(int fd, off64_t offset, int whence) {
  BRAHMA_MAP_OR_FAIL(lseek64);
  DLIO_LOGGER_START(fd);
  off64_t ret = __real_lseek64(fd, offset, whence);
  DLIO_LOGGER_END();
  return ret;
}

ssize_t brahma::POSIXDLIOProfiler::pread(int fd, void *buf, size_t count, off_t offset) {
  BRAHMA_MAP_OR_FAIL(pread);
  DLIO_LOGGER_START(fd);
  ssize_t ret = __real_pread(fd, buf, count, offset);
  DLIO_LOGGER_END();
  return ret;
}

ssize_t brahma::POSIXDLIOProfiler::pread64(int fd, void *buf, size_t count, off64_t offset) {
  BRAHMA_MAP_OR_FAIL(pread64);
  DLIO_LOGGER_START(fd);
  ssize_t ret = __real_pread64(fd, buf, count, offset);
  DLIO_LOGGER_END();
  return ret;
}

ssize_t brahma::POSIXDLIOProfiler::pwrite(int fd, const void *buf, size_t count, off64_t offset) {
  BRAHMA_MAP_OR_FAIL(pwrite);
  DLIO_LOGGER_START(fd);
  ssize_t ret = __real_pwrite(fd, buf, count, offset);
  DLIO_LOGGER_END();
  return ret;
}

ssize_t brahma::POSIXDLIOProfiler::pwrite64(int fd, const void *buf, size_t count, off64_t offset) {
  BRAHMA_MAP_OR_FAIL(pwrite64);
  DLIO_LOGGER_START(fd);
  ssize_t ret = __real_pwrite64(fd, buf, count, offset);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::fsync(int fd) {
  BRAHMA_MAP_OR_FAIL(fsync);
  DLIO_LOGGER_START(fd);
  int ret = __real_fsync(fd);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::fdatasync(int fd) {
  BRAHMA_MAP_OR_FAIL(fdatasync);
  DLIO_LOGGER_START(fd);
  int ret = __real_fdatasync(fd);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::openat(int dirfd, const char *pathname, int flags, ...) {
  BRAHMA_MAP_OR_FAIL(openat);
  DLIO_LOGGER_START(dirfd);
  int ret = -1;
  if (flags & O_CREAT) {
    va_list args;
    va_start(args, flags);
    int mode = va_arg(args, int);
    va_end(args);
    ret = __real_openat(dirfd, pathname, flags, mode);
  } else {
    ret = __real_openat(dirfd, pathname, flags);
  }
  DLIO_LOGGER_END();
  return ret;
}

void *brahma::POSIXDLIOProfiler::mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
  BRAHMA_MAP_OR_FAIL(mmap);
  DLIO_LOGGER_START(fd);
  void* ret = __real_mmap(addr, length, prot, flags, fd, offset);
  DLIO_LOGGER_END();
  return ret;
}

void *brahma::POSIXDLIOProfiler::mmap64(void *addr, size_t length, int prot, int flags, int fd, off64_t offset) {
  BRAHMA_MAP_OR_FAIL(mmap64);
  DLIO_LOGGER_START(fd);
  void* ret = __real_mmap64(addr, length, prot, flags, fd, offset);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::__xstat(int vers, const char *path, struct stat *buf) {
  BRAHMA_MAP_OR_FAIL(__xstat);
  DLIO_LOGGER_START(path);
  int ret = __real___xstat(vers, path, buf);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::__xstat64(int vers, const char *path, struct stat64 *buf) {
  BRAHMA_MAP_OR_FAIL(__xstat64);
  DLIO_LOGGER_START(path);
  int ret = __real___xstat64(vers, path, buf);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::__lxstat(int vers, const char *path, struct stat *buf) {
  BRAHMA_MAP_OR_FAIL(__lxstat);
  DLIO_LOGGER_START(path);
  int ret = __real___lxstat(vers, path, buf);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::__lxstat64(int vers, const char *path, struct stat64 *buf) {
  BRAHMA_MAP_OR_FAIL(__lxstat64);
  DLIO_LOGGER_START(path);
  int ret = __real___lxstat64(vers, path, buf);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::__fxstat(int vers, int fd, struct stat *buf) {
  BRAHMA_MAP_OR_FAIL(__fxstat);
  DLIO_LOGGER_START(fd);
  int ret = __real___fxstat(vers, fd, buf);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::__fxstat64(int vers, int fd, struct stat64 *buf) {
  BRAHMA_MAP_OR_FAIL(__fxstat64);
  DLIO_LOGGER_START(fd);
  int ret = __real___fxstat64(vers, fd, buf);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::mkdir(const char *pathname, mode_t mode) {
  BRAHMA_MAP_OR_FAIL(mkdir);
  DLIO_LOGGER_START(pathname);
  int ret = __real_mkdir(pathname, mode);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::rmdir(const char *pathname) {
  BRAHMA_MAP_OR_FAIL(rmdir);
  DLIO_LOGGER_START(pathname);
  int ret = __real_rmdir(pathname);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::chdir(const char *path) {
  BRAHMA_MAP_OR_FAIL(chdir);
  DLIO_LOGGER_START(path);
  int ret = __real_chdir(path);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::link(const char *oldpath, const char *newpath) {
  BRAHMA_MAP_OR_FAIL(link);
  DLIO_LOGGER_START(oldpath);
  int ret = __real_link(oldpath, newpath);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::linkat(int fd1, const char *path1, int fd2, const char *path2, int flag) {
  BRAHMA_MAP_OR_FAIL(linkat);
  DLIO_LOGGER_START(fd1);
  int ret = __real_linkat(fd1, path1, fd2, path2, flag);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::unlink(const char *pathname) {
  BRAHMA_MAP_OR_FAIL(unlink);
  DLIO_LOGGER_START(pathname);
  int ret = __real_unlink(pathname);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::symlink(const char *path1, const char *path2) {
  BRAHMA_MAP_OR_FAIL(symlink);
  DLIO_LOGGER_START(path1);
  int ret = __real_symlink(path1, path2);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::symlinkat(const char *path1, int fd, const char *path2) {
  BRAHMA_MAP_OR_FAIL(symlinkat);
  DLIO_LOGGER_START(path1);
  int ret = __real_symlinkat(path1, fd, path2);
  DLIO_LOGGER_END();
  return ret;
}

ssize_t brahma::POSIXDLIOProfiler::readlink(const char *path, char *buf, size_t bufsize) {
  BRAHMA_MAP_OR_FAIL(readlink);
  DLIO_LOGGER_START(path);
  ssize_t ret = __real_readlink(path, buf, bufsize);
  DLIO_LOGGER_END();
  return ret;
}

ssize_t brahma::POSIXDLIOProfiler::readlinkat(int fd, const char *path, char *buf, size_t bufsize) {
  BRAHMA_MAP_OR_FAIL(readlinkat);
  DLIO_LOGGER_START(fd);
  ssize_t ret = __real_readlinkat(fd, path, buf, bufsize);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::rename(const char *oldpath, const char *newpath) {
  BRAHMA_MAP_OR_FAIL(rename);
  DLIO_LOGGER_START(oldpath);
  int ret = __real_rename(oldpath, newpath);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::chmod(const char *path, mode_t mode) {
  BRAHMA_MAP_OR_FAIL(chmod);
  DLIO_LOGGER_START(path);
  int ret = __real_chmod(path, mode);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::chown(const char *path, uid_t owner, gid_t group) {
  BRAHMA_MAP_OR_FAIL(chown);
  DLIO_LOGGER_START(path);
  int ret = __real_chown(path, owner, group);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::lchown(const char *path, uid_t owner, gid_t group) {
  BRAHMA_MAP_OR_FAIL(lchown);
  DLIO_LOGGER_START(path);
  int ret = __real_lchown(path, owner, group);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::utime(const char *filename, const utimbuf *buf) {
  BRAHMA_MAP_OR_FAIL(utime);
  DLIO_LOGGER_START(filename);
  int ret = __real_utime(filename, buf);
  DLIO_LOGGER_END();
  return ret;
}

DIR* brahma::POSIXDLIOProfiler::opendir(const char *name) {
  BRAHMA_MAP_OR_FAIL(opendir);
  DLIO_LOGGER_START(name);
  DIR* ret = __real_opendir(name);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::fcntl(int fd, int cmd, long arg) {
  BRAHMA_MAP_OR_FAIL(fcntl);
  DLIO_LOGGER_START(fd);
  int ret = __real_fcntl(fd, cmd, arg);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::dup(int oldfd) {
  BRAHMA_MAP_OR_FAIL(dup);
  DLIO_LOGGER_START(oldfd);
  int ret = __real_dup(oldfd);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::dup2(int oldfd, int newfd) {
  BRAHMA_MAP_OR_FAIL(dup2);
  DLIO_LOGGER_START(oldfd);
  int ret = __real_dup2(oldfd, newfd);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::mkfifo(const char *pathname, mode_t mode) {
  BRAHMA_MAP_OR_FAIL(mkfifo);
  DLIO_LOGGER_START(pathname);
  int ret = __real_mkfifo(pathname, mode);
  DLIO_LOGGER_END();
  return ret;
}

mode_t brahma::POSIXDLIOProfiler::umask(mode_t mask) {
  BRAHMA_MAP_OR_FAIL(umask);
  DLIO_LOGGER_START(mask);
  mode_t ret = __real_umask(mask);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::access(const char *path, int amode) {
  BRAHMA_MAP_OR_FAIL(access);
  DLIO_LOGGER_START(path);
  int ret = __real_access(path, amode);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::faccessat(int fd, const char *path, int amode, int flag) {
  BRAHMA_MAP_OR_FAIL(faccessat);
  DLIO_LOGGER_START(fd);
  int ret = __real_faccessat(fd, path, amode, flag);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::remove(const char *pathname) {
  BRAHMA_MAP_OR_FAIL(remove);
  DLIO_LOGGER_START(pathname);
  int ret = __real_remove(pathname);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::truncate(const char *pathname, off_t length) {
  BRAHMA_MAP_OR_FAIL(truncate);
  DLIO_LOGGER_START(pathname);
  int ret = __real_truncate(pathname, length);
  DLIO_LOGGER_END();
  return ret;
}

int brahma::POSIXDLIOProfiler::ftruncate(int fd, off_t length) {
  BRAHMA_MAP_OR_FAIL(ftruncate);
  DLIO_LOGGER_START(fd);
  int ret = __real_ftruncate(fd, length);
  DLIO_LOGGER_END();
  return ret;
}
