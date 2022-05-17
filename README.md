# DrawPlots
The plots tool ManagerUtils is credited by [Yi-Mu Enoch Chen](https://github.com/yimuchen).

If you want to use it, first change all path name in the package and rootlogan.cc.

Second, add these in your plot scripts:

using namespace mgr;
mgr::FUNCTION

Before loading the script:

root -l rootlogan.cc
(root mode)
.x Draw_plot_script.cc

