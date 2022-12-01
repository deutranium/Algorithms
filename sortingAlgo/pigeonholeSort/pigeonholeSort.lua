--- Sort an array using the pigeonhole sort algorithm.
--- @param t table
--- @return table
local function pigeonholeSort(t)
    local n = #t
    local min = math.huge
    local max = -math.huge
    for i = 1, n do
        if t[i] < min then
            min = t[i]
        end
        if t[i] > max then
            max = t[i]
        end
    end
    local holes = {}
    for i = 1, n do
        holes[i] = 0
    end
    for i = 1, n do
        holes[t[i] - min + 1] = holes[t[i] - min + 1] + 1
    end
    local k = 1
    for i = 1, n do
        while holes[i] > 0 do
            t[k] = i + min - 1
            k = k + 1
            holes[i] = holes[i] - 1
        end
    end
    return t
end

return pigeonholeSort