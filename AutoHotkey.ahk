#,::
IfWinExist ahk_class VanDyke Software - SecureCRT
    ifWinActive
        WinMinimize
    else
	WinActivate
else
	Run E:\SecureCRT\SecureCRT.exe
return

;; #2::
;; IfWinExist ahk_class PuTTY
;;     ifWinActive
;;         WinMinimize
;;     else
;; 	WinActivate
;; else
;; 	Run E:\putty\putty.exe
;; return

#.::
ifWinExist ahk_class Emacs
   ifWinActive
      WinMinimize
   else
      WinActivate
else
    Run E:\emacs-24.2\bin\runemacs.exe
return


#/::
ifWinExist ahk_class TTOTAL_CMD
   ifWinActive
	WinMinimize
   else
	WinActivate
else
   Run E:\totalcmd\totalcmd.exe	
return





;; #5::
;; ifWinExist ahk_class PX_WINDOW_CLASS
;;    ifWinActive
;;       WinMinimize
;;    else
;;       WinActivate
;; else
;;     Run E:\Sublime Text 2\sublime_text.exe
;; return
