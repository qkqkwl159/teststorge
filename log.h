#ifdef __LOG_H__
#define __LOG_H__

#ifdef DEBUG
#define LOG(...) do{printf("LINE : %d FUNC : %s ", __LINE__, __func__);printf(_VA_ARGS__);}while(0)
#else
#define LOG(X)
#endif

#endif
