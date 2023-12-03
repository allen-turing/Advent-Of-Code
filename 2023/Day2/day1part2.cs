namespace Day2;

public class day1part2
{
    public day1part2()
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
            int maxRed = 0, maxGreen = 0, maxBlue = 0;
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
                        maxRed = Math.Max(maxRed, red);
                    }
                    else if (blockType == "green")
                    {
                        green = blockCount;
                        maxGreen = Math.Max(maxGreen, green);

                    }
                    else if (blockType == "blue")
                    {
                        blue = blockCount;
                        maxBlue = Math.Max(maxBlue, blue);
                    }
                    if (red > allowedRed || blue > allowedBlue || green > allowedGreen)
                    {
                    }
                }
            }

            totalCount += (maxRed * maxGreen * maxBlue);
        }
        System.Console.WriteLine($"Total Count {totalCount}");
    }
}