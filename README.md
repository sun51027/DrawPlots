# DrawPlots
The plots tool ManagerUtils is credited by Yi-Mu Enoch Chen.

If you want to use it, first change all path name in the package and rootlogan.cc.

Second, add 

    ```cc

		using namespace mgr;

		mgr::FUNCTION

		```cc

Before loading the script:

    ```cc

   	root -l rootlogan.cc

		(root mode)

		.x Draw_plot_script.cc

    ```

