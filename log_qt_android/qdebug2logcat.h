#ifndef QDEBUG2LOGCAT
#define QDEBUG2LOGCAT

#ifdef ANDROID
void installLogcatMessageHandler(const char *TAG);
#else
#define installLogcatMessageHandler(TAG)

#endif // QDEBUG2LOGCAT

