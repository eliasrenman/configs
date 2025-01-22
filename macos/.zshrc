# if [[ $TERM_PROGRAM != "WarpTerminal" ]]; then
##### WHAT YOU WANT TO DISABLE FOR WARP - BELOW

# parse_git_branch() {
#     git_status="$(git status 2> /dev/null)"
#     pattern="On branch ([^[:space:]]*)"
#     if [[ ! ${git_status} =~ "(working (tree|directory) clean)" ]]; then
#         state="*"
#     fi
#     if [[ ${git_status} =~ ${pattern} ]]; then
#       branch=${match[1]}
#       branch_cut=${branch:0:35}
#       if (( ${#branch} > ${#branch_cut} )); then
#           echo "[${branch_cut}…${state}]"
#       else
#           echo "[${branch}${state}]"
#       fi
#     fi
# }

# setopt PROMPT_SUBST
# PROMPT='%{%F{blue}%}%9c%{%F{green}%} $(parse_git_branch)%{%F{none}%}$ '

# jdk() {
#         version=$1
#         export JAVA_HOME=$(/usr/libexec/java_home -v"$version");
#         java -version
#  }

##### WHAT YOU WANT TO DISABLE FOR WARP - ABOVE
# fi

alias ..="cd .."
alias ...="cd ../.."
alias ....="cd ../../.."
alias .....="cd ../../../.."
alias ......="cd ../../../../.."

 export NVM_DIR="$HOME/.nvm"
 [ -s "/opt/homebrew/opt/nvm/nvm.sh" ] && \. "/opt/homebrew/opt/nvm/nvm.sh"  # This loads nvm
 [ -s "/opt/homebrew/opt/nvm/etc/bash_completion.d/nvm" ] && \. "/opt/homebrew/opt/nvm/etc/bash_completion.d/nvm"  # This loads nvm bash_completion
