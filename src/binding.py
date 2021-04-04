from disp import disp
import sys
a = sys.argv

if len(a) > 2:
    disp(int(a[1]),int(a[2]))
else:
    print("Please specify 2 arguments.")
    pass
