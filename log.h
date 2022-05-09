#ifdef DEBUG
#define LOG(...) do{ printf("LINE: %d FUNC: %s ", __LINE__, __func__); printf("\n"); printf(__VA_ARGS__); }while(0);
#else
#define LOG(X)
#endif
