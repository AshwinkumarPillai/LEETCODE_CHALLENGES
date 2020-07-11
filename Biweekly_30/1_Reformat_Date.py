class Solution:
    def reformatDate(self, date: str) -> str:
        month = {"Jan":"01", "Feb":"02", "Mar":"03", "Apr":"04", "May":"05", "Jun":"06", "Jul":"07", "Aug":"08", "Sep":"09", "Oct":"10", "Nov":"11", "Dec":"12"}
        arr = date.split(' ')
        temp = arr[0]
        arr[0] = arr[2]
        arr[2] = temp[:-2]
        arr[1] = month[arr[1]]
        if int(arr[2]) < 10 and len(arr[2]) < 2:
            arr[2] = "0" + arr[2]
        return "-".join(arr)