"""This is a script to quickly add a new campaign"""

from jb_utils.monitor.monitor_db import add_campaign
import jb_utils.monitor.grid_monitor as grid_monitor


def main():
    monitor = grid_monitor.GridMonitor()
    while True:
        print("Enter string that campaign starts with")
        user_startsWith = raw_input(">>> ")
        print("Enter any matching string that you need (or leave blank if none needed)")
        user_matchString = raw_input('>>> ')
        if user_matchString == "":
            task = monitor.query(constraints = lambda t: t.jobName.startswith(user_startsWith))
        else: 
            task = monitor.query(constraints = lambda t: t.jobName.startswith(user_startsWith) and t.jobName.find(user_matchString) !=-1)
        print(task)
        print("Enter the task name or exit if you're not happy with the tasks above")
        user_taskName = raw_input(">>> ")
        if user_taskName == "exit":
            break
        return add_campaign(user_taskName, task)

if __name__ == "__main__":
    main()
