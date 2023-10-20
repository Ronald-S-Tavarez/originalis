# Directories
$SRC_DIR = ".\source"
$TEST_DIR = ".\tests"
$BIN_DIR = ".\binary"
$BUILD_DIR = ".\build"

# Ensure output directories exist
if (-not (Test-Path -Path $BIN_DIR)) { New-Item -Path $BIN_DIR -ItemType Directory }
if (-not (Test-Path -Path $BUILD_DIR)) { New-Item -Path $BUILD_DIR -ItemType Directory }

# Compile with GCC
gcc "$TEST_DIR\core\log.c" "$SRC_DIR\core\log.c" "$SRC_DIR\core\string.c" -o "$BIN_DIR\log_test_gcc.exe" -I$SRC_DIR
Move-Item -Path *.o -Destination $BUILD_DIR

Write-Output "Compilation complete!"
