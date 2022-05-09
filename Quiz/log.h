#ifdef DEBUG
#define LOG(...) do{ printf("LINE: %d FUNC: %s LOG:", __LINE__, __func__); printf(__VA_ARGS__);  printf("\n"); }while(0);
#else
#define LOG(...)
#endif
