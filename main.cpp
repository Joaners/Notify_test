#include <libnotify/notify.h>
#include <QCoreApplication>

int notification_show(char *title, char *body, char *icon);

int main(int argc, char *argv[])
{
    notification_show("cheery", "here is body...", "/usr/share/pixmaps/apple-green.png");
    sleep(10);
    notification_show("cheery", NULL, NULL);
    printf("UNIX/n");
    return 0;
}

int notification_show(char *title, char *body, char *icon)
{
    GError *error = NULL;
    NotifyNotification *notify_p;
    if (title == NULL)
        return -1;
    //you should init notify using app's name
    if(notify_is_initted() == FALSE)
        if(notify_init("argv[0]") == FALSE){
            return -1;
        }

    notify_p = notify_notification_new(title, body, icon);

    //miliseconds, NOTIFY_EXPIRES_DEFAULT NOTIFY_EXPIRES_NEVER
    notify_notification_set_timeout(notify_p, 1000);

    //NOTIFY_URGENCY_LOW,NOTIFY_URGENCY_NORMAL, NOTIFY_URGENCY_CRITICAL,
    notify_notification_set_urgency (notify_p,NOTIFY_URGENCY_NORMAL);
    //notify_notification_update(title, body, icon, NULL);
    //notify_notification_close(notify_p, &error);
    if (notify_notification_show(notify_p, &error) == FALSE)
        return -1;
    //notify_uninit();
    return 0;
}
