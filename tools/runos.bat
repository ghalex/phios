@ECHO OFF

:menu
CLS
ECHO.
ECHO Copyright (c) Alexandru Ghiura.
ECHO.
ECHO --++++++++++++++++++++++++++++++++++++++++++++++++++--
ECHO  PRESS 1, 2, 3 or 4 to select your task, or 5 to EXIT
ECHO --++++++++++++++++++++++++++++++++++++++++++++++++++--
ECHO.
ECHO 1 - Run
ECHO 2 - Update
ECHO 3 - Update and Run
ECHO 4 - Rebuild
ECHO 5 - Exit
ECHO.

:read
SET /P M=Type 1, 2, 3, 4 or 5, then press ENTER: 
IF %M%==1 GOTO :run
IF %M%==2 GOTO :update
IF %M%==3 GOTO :update_run
IF %M%==4 GOTO :rebuild
IF %M%==5 GOTO :eof

:run
CALL run.bat
GOTO :read

:update
CALL update.bat
GOTO :read

:update_run
CALL update.bat
SLEEP 1
CALL run.bat
GOTO :read

:rebuild
CD ..
CD source
CD phi
make clean
make all
CD ..
CD ..
CD tools
PAUSE
GOTO :menu

:eof