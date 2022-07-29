parse_git_branch() {
    git_status="$(git status 2> /dev/null)"
    pattern="On branch ([^[:space:]]*)"
    if [[ ! ${git_status} =~ "(working (tree|directory) clean)" ]]; then
        state="*"
    fi
    if [[ ${git_status} =~ ${pattern} ]]; then
      branch=${match[1]}
      branch_cut=${branch:0:35}
      if (( ${#branch} > ${#branch_cut} )); then
          echo "[${branch_cut}…${state}]"
      else
          echo "[${branch}${state}]"
      fi
    fi
}

setopt PROMPT_SUBST
PROMPT='%{%F{blue}%}%9c%{%F{green}%} $(parse_git_branch)%{%F{none}%}$ '
export ANDROID_HOME=$HOME/Library/Android/sdk
export PATH=$PATH:$ANDROID_HOME/tools
export PATH=$PATH:$ANDROID_HOME/platform-tools

jdk() {
        version=$1
        export JAVA_HOME=$(/usr/libexec/java_home -v"$version");
        java -version
 }

alias ..="cd .."
alias ...="cd ../.."
alias ....="cd ../../.."
alias .....="cd ../../../.."
alias ......="cd ../../../../.."

export NVM_DIR="$([ -z "${XDG_CONFIG_HOME-}" ] && printf %s "${HOME}/.nvm" || printf %s "${XDG_CONFIG_HOME}/nvm")"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"

killport() {
    readonly port=${1:?"The port must be specified."}
    pid=${lsof -i tcp:"$port" | grep LISTEN | awk '{print $2}'}
    kill -15 $pid;
}

resetlast() {
    git reset --soft HEAD~1
}
