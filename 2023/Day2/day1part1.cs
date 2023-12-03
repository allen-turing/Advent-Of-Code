namespace Day2;

public class day1part1
{
    public day1part1()
    {
        string fileName = "in";
        var file = File.ReadAllLines(fileName);
        int allowedRed = 12, allowedGreen = 13, allowedBlue = 14;
        int totalCount = 0;
        foreach (var lineText in file)
        {
            int red = 0, blue = 0, green = 0;
            var text = lineText.Split(':');
            int serialNumber = Convert.ToInt32(text[0].Split(' ')[1]);
            var blocks = text[1].Split(';');
            bool isValid = true;
            foreach (var blockItem in blocks)
            {
                var cubes = blockItem.Split(',');
                foreach (var cubeItem in cubes)
                {
                    var cubeBlocks = cubeItem.Split(' ');
                    int blockCount = Convert.ToInt32(cubeBlocks[1]);
                    string blockType = cubeBlocks[2];
                    if (blockType == "red")
                    {
                        red = blockCount;
                    }
                    else if (blockType == "green")
                    {
                        green = blockCount;
                    }
                    else if (blockType == "blue")
                    {
                        blue = blockCount;
                    }
                    if (red > allowedRed || blue > allowedBlue || green > allowedGreen)
                    {
                        isValid = false;
                        break;
                    }
                }
                if (!isValid) break;
            }
            if (isValid)
            {
                totalCount += serialNumber;
            }
        }
        System.Console.WriteLine($"Total Count {totalCount}");
    }
}