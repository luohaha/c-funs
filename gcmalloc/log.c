#include "gcmalloc.h"

static void error(char *msg) {
  log_print("error", msg);
}

static void warn(char *msg) {
  log_print("warn", msg);
}

static void info(char *msg) {
  log_print("info", msg);
}

static void debug(char *msg) {
  log_print("debug", msg);
}

static void log_print(char *type, char *msg) {
  fprintf(stderr, "[%s] : %s\n", type, msg);
}
