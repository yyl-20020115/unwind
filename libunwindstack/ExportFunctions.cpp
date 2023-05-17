#include "ExportFunctions.h"
#include <unwindstack/Unwinder.h>
#include <android/log.h> 

int UNWIND_DumpStack(const char* path)
{
    __android_log_print(ANDROID_LOG_VERBOSE, "DOBBY", "UNWIND_DumpStack ENTER");
    if(path!=0){
        FILE* fp = fopen(path,"a");
        if(fp!=0)
        {
            pid_t pid = getpid();
            fprintf(fp,"UNWIND STACK FOR %d\n",pid);

            unwindstack::Regs* regs = unwindstack::Regs::RemoteGet(pid);

            unwindstack::UnwinderFromPid unwinder(1024, pid);
            if (unwinder.Init(regs->Arch())) {
                unwinder.SetRegs(regs);
                unwinder.Unwind();

                // Print the frames.
                for (size_t i = 0; i < unwinder.NumFrames(); i++) {
                    fprintf(fp,"%s\n", unwinder.FormatFrame(i).c_str());
                }
            }
            fclose(fp);
        }

    }
    __android_log_print(ANDROID_LOG_VERBOSE, "DOBBY", "UNWIND_DumpStack LEAVE");

    return -1;
}