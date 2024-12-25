home=$(qmk config | grep user.qmk_home | cut -d= -f2)

cd $home
make SKIP_GIT=yes keyball/keyball39:tencho

# explorer.exe .build
