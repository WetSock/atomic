cd /home/amadeo/Atomic/atomic/atom
python3 manage.py runserver &
sleep 2
google-chrome --kiosk --disable-pinch --overscroll-history-navigation=0 http://127.0.0.1:8000 &
disown