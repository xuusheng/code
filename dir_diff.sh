#!/bin/bash

if [ $# -ne 2 ];then
        ColorPrint "$0 <src dir>  <dst dir>" "COLOR_RED"
        exit 1
fi

ColorPrint()
{
        if [ $# -lt 2 ];then
                return 1;
        fi

        STR_PRE="";
        if [ "$2" == "COLOR_BLACK" ];then
                STR_PRE="\033[0;30m"
        elif [ "$2" == "COLOR_RED" ];then
                STR_PRE="\033[0;31m"
        elif [ "$2" == "COLOR_GREEN" ];then
                STR_PRE="\033[0;32m"
        elif [ "$2" == "COLOR_YELLOW" ];then
                STR_PRE="\033[0;33m"
        elif [ "$2" == "COLOR_BLUE" ];then
                STR_PRE="\033[0;34m"
        elif [ "$2" == "COLOR_PUPPLE" ];then
                STR_PRE="\033[0;35m"
        elif [ "$2" == "COLOR_CYAN" ];then
                STR_PRE="\033[0;36m"
        elif [ "$2" == "COLOR_WHITE" ];then
                STR_PRE="\033[0;37m"
        fi

        echo -ne "${STR_PRE}${1}\033[0m";

        return 0;
}


STR_MSG="";
FillPrint()
{
        if [ $# -lt 2 ];then
                return 1;
        fi

        STR_SPACE=""
        MSG_LEN=${#STR_MSG};
        while [ $MSG_LEN -gt 0 ]
        do
                STR_SPACE="$STR_SPACE ";
                MSG_LEN=`echo "$MSG_LEN - 1" | bc`;
        done;

        echo -ne "\r${STR_SPACE}";
        STR_MSG=$1;

        #echo $2;

        ColorPrint "\r$STR_MSG" $2;

        return $?
}

SRC_DIR="$1";
DST_DIR="$2";

#add '/' to each SRC_DIR & DST_DIR
SRC_DIR_NAME_LEN=${#SRC_DIR};
STR_START=`echo "$SRC_DIR_NAME_LEN - 1" | bc`;

if [ '/' != ${SRC_DIR:$STR_START:$SRC_DIR_NAME_LEN} ];then
        SRC_DIR="${SRC_DIR}/";
        SRC_DIR_NAME_LEN=${#SRC_DIR};
fi

DST_DIR_NAME_LEN=${#DST_DIR};
STR_DST_START=`echo "$DST_DIR_NAME_LEN - 1" | bc`;

if [ '/' != ${DST_DIR:$STR_DST_START:$DST_DIR_NAME_LEN} ];then
        DST_DIR="${DST_DIR}/";
fi


#define diff log & clear
DIFF_FILE_LOG='/tmp/dir_diff_tmp.log';
nRet=0;

\rm "${DIFF_FILE_LOG}" -f;

#compare
for i in `find ${SRC_DIR}`;
do
        if ! [ -f "$i" ];then
                continue;
        fi

        FILE_NAME_LEN=${#i};
        FILE_NAME=${i:$SRC_DIR_NAME_LEN:${FILE_NAME_LEN}};
        CMP_SRC_FILE="${SRC_DIR}${FILE_NAME}";
        CMP_DST_FILE="${DST_DIR}${FILE_NAME}";

        #do not compare hidden file
        if [ "." != ${FILE_NAME:0:1} ];then
                FillPrint "Compare ${FILE_NAME}" "COLOR_CYAN"
                if ! [ -f "${CMP_DST_FILE}" ]; then
                        ColorPrint "\n${CMP_DST_FILE} not exist\n" "COLOR_RED";
                        nRet=1
                        continue;
                fi
                diff "${CMP_SRC_FILE}" "${CMP_DST_FILE}" >> $DIFF_FILE_LOG;
                if [ 0 -eq $? ]; then
                         a=1;
                #        FillPrint "Exactly OK" "COLOR_CYAN";
                else
                        ColorPrint "\nNOT OK, ${FILE_NAME}\n" "COLOR_RED";
                        nRet=1;
                        continue;
                fi
        fi
done;

#end of FillPrint
echo -e "\n";


ColorPrint "\n\n=======================================================================\n" "COLOR_GREEN";
ColorPrint "Compare ${SRC_DIR}  ====>  ${DST_DIR}\n" "COLOR_GREEN";
ColorPrint "=======================================================================\n" "COLOR_GREEN";

if [ 0 -eq $nRet ];then
        ColorPrint "RESULT:Exactly the same ~ ~ ~ ~\n\n" "COLOR_GREEN";
else
        ColorPrint "RESULT:Difference!!!!See ${DIFF_FILE_LOG}\n\n" "COLOR_RED";
fi

exit $nRet;