#!/bin/zsh

# Define ANSI color escape codes
RED='\033[0;31m' # Red color
GREEN='\033[0;92m' # Green color
BLUE='\033[38;5;74m' # Light blue color
NC='\033[0m'     # No color (reset)

userProfile=$HOME

chmod +x "$userProfile/CVPro_Competition_Kit-main/cvpro.zsh"
chmod +x "$userProfile/CVPro_Competition_Kit-main/install.zsh"

echo ""
echo "${GREEN}CVPRO Competition Kit${NC}"
echo "---------------------"
echo ""
echo "${BLUE}Installing Libraries...${NC}"
echo ""

# Install arduino-cli
brew install arduino-cli

# Set-up arduino-cli
arduino-cli config init

# Call the install script
"$userProfile/CVPro_Competition_Kit-main/install.zsh"
