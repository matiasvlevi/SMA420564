from disp import disp
import sys
a = sys.argv

if len(a) > 2:
    disp(a[1],a[2])
else:
    print("Please specify 2 arguments.")
    pass
